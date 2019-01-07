//
// Created by davidregev on 31/12/18.
//


#include <pthread>
#include "MySerialServer.h"

void MySerialServer::open(int port) {

}

void MySerialServer::stop() {

}

void* MySerialServer::thread_OpenDataServer(void* arg) {
    struct TCPDataServer* params = (struct TCPDataServer*) arg;

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

    //TODO: how to close the socket
//    params->data->addSocket(socketFd);

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


    //accept actual connection from the client
    newsockfd = accept(socketFd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);


    //if connections with the client failed
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    string dataStr;

    while(true)
    {
        char buf[1024];
        int numBytesRead = recv(newsockfd, buf, sizeof(buf), 0);


        if (numBytesRead > 0)
        {
            for (int i=0; i<numBytesRead; i++)
            {
                char c = buf[i];
                if (c == '\n')
                {
                    if (dataStr.length() > 0)
                    {
                        //TODO: call to client handler
                    }
                }
                else dataStr += c;
            }
        }
        else
        {
            break;
        }
    }

    return nullptr;
}