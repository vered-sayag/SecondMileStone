//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SERVER_SIDE_H
#define SECONDMIILESTONE_SERVER_SIDE_H


#include "ClientHandler.h"

namespace server_side{
    class Server {
    protected:
        ClientHandler *clientHandler;
    public:
        Server(ClientHandler* c) : clientHandler(c) {
        }
        virtual void open(int port)=0;
        virtual void stop()=0;

        virtual ~Server() {
            delete (clientHandler);
        }
    };
}


#endif //SECONDMIILESTONE_SERVER_SIDE_H
