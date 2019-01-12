//
// Created by vered on 1/12/19.
//

#include "MyTCPserver.h"
//
// Created by vered on 1/11/19.
//


#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>


void server_side::MyTCPserver::open(int port, ClientHandler *c) {
    TCPDataServer *params;
    params = new TCPDataServer();
    params->server = this;
    params->port = port;
    params->client = c;
    params->shouldStop = &shouldStop;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_OpenDataServer, params);
    trids.push_back(trid);
}

void server_side::MyTCPserver::stop() {
    shouldStop = true;
    for (int i = 0; i < trids.size(); i++) {
        pthread_join(trids[i], nullptr);
    }
}


void *server_side::MyTCPserver::thread_OpenDataServer(void *arg) {
    TCPDataServer *params = (TCPDataServer *) arg;

    int socketFd; // main socket fileDescriptor
    int newsockfd; // new socket fileDescriptor
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;

    //creating socket object
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    //if creation faild
    if (socketFd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // tcp server
    serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
    serv_addr.sin_port = htons(params->port); //init server port

    //bind the host address using bind() call
    if (bind(socketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //if binding faild
        perror("ERROR on binding");
        exit(1);
    }


    params->server->unique( socketFd,params->shouldStop,params->client );

    close(socketFd);
    delete (params->client);
    delete (params);
    return nullptr;
}
