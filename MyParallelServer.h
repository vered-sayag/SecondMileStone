//
// Created by vered on 1/11/19.
//

#ifndef SECONDMIILESTONE_MYPARALLELSERVER_H
#define SECONDMIILESTONE_MYPARALLELSERVER_H

#include <list>
#include <vector>
#include "Server.h"
#include "ClientHandler.h"
#include "MyTCPserver.h"

namespace server_side {

    class MyParallelServer : public MyTCPserver {

        static void *thread_CallClientHandler(void *arg);
    protected:

        virtual void unique(int socket, bool *shouldStop, ClientHandler *client);

    };

    typedef struct {
        int socket;
        ClientHandler *client;
    } CallClientHandlerData;
}

#endif //SECONDMIILESTONE_MYPARALLELSERVER_H
