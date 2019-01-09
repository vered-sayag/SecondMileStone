//
// Created by davidregev on 31/12/18.
//


#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "MySerialServer.h"
#include <stdio.h>


void server_side::MySerialServer::open(int port) {
    TCPDataServer *params;
    params = new TCPDataServer();
    params->port = port;
    params->client= clientHandler;
    params->shouldStop = & shouldStop;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_OpenDataServer, params);
}

void server_side::MySerialServer::stop() {
    shouldStop=1;

}

void* MySerialServer::thread_OpenDataServer(void* arg) {
    TCPDataServer* params = (TCPDataServer*) arg;

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


    //start listening for the clients using the main socket
    listen(socketFd,1);
    clilen = sizeof(cli_addr);

    while (!*params->shouldStop) {

        //accept actual connection from the client
        newsockfd = accept(socketFd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);


        //if connections with the client failed
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        params->client->handleClient(newsockfd);
    }

    close(socketFd);
    return nullptr;
}