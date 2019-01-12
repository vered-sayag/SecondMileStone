//
// Created by vered on 1/12/19.
//

#ifndef SECONDMIILESTONE_MYTCPSERVER_H
#define SECONDMIILESTONE_MYTCPSERVER_H


#include <list>
#include <vector>
#include "Server.h"
#include "ClientHandler.h"

namespace server_side {

    class MyTCPserver : public Server {

        vector<pthread_t> trids;
        bool shouldStop = false;

        static void *thread_OpenDataServer(void *arg);

    protected:

        virtual void unique(int socket, bool *shouldStop, ClientHandler *client) = 0;

    public:

        void open(int port, ClientHandler *c);

        void stop();


    };

    typedef struct {
        MyTCPserver* server;
        int port;
        bool *shouldStop;
        ClientHandler *client;
    } TCPDataServer;

}


#endif //SECONDMIILESTONE_MYTCPSERVER_H
