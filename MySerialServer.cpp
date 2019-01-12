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



void server_side::MySerialServer::unique(int socket, bool *shouldStop, ClientHandler *client) {

    int socketFd= socket;
    int newsockfd; // new socket fileDescriptor
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;



    //start listening for the clients using the main socket
    listen(socketFd, 1);
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
            if(*shouldStop){
                break;
            }
            if (errno == EWOULDBLOCK) {
                continue;
            }
            perror("ERROR on accept");
            exit(1);
        }
        client->handleClient(newsockfd);

    }

}