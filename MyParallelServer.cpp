//
// Created by vered on 1/11/19.
//

#include "MyParallelServer.h"
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void *server_side::MyParallelServer::thread_CallClientHandler(void *arg) {
    CallClientHandlerData *callClientHandlerData = (CallClientHandlerData *) arg;
    callClientHandlerData->client->handleClient(callClientHandlerData->socket);
    delete (callClientHandlerData);
    return nullptr;
}

void server_side::MyParallelServer::unique(int socket, bool *shouldStop, ClientHandler *client) {

    int socketFd = socket;
    int newsockfd; // new socket fileDescriptor
    int clilen;

    vector<pthread_t> trids;

    struct sockaddr_in serv_addr, cli_addr;



    //start listening for the clients using the main socket
    listen(socketFd, SOMAXCONN);


    clilen = sizeof(cli_addr);


    while (!*shouldStop) {


        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        //accept actual connection from the client

        newsockfd = accept(socketFd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);


        //if connections with the client failed
        if (newsockfd < 0) {
            if (*shouldStop) {
                break;
            }
            if (errno == EWOULDBLOCK) {
                continue;
            }
            perror("ERROR on accept");
            exit(1);
        }
        CallClientHandlerData *callClientHandlerData;
        callClientHandlerData = new CallClientHandlerData();

        callClientHandlerData->socket = newsockfd;
        callClientHandlerData->client = client;
        pthread_t trid;
        pthread_create(&trid, nullptr, thread_CallClientHandler, callClientHandlerData);
        trids.push_back(trid);


    }

    for (int i = 0; i < trids.size(); i++) {
        pthread_join(trids[i], nullptr);
    }

}
