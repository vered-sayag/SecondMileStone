//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SERVER_SIDE_H
#define SECONDMIILESTONE_SERVER_SIDE_H


#include "ClientHandler.h"

namespace server_side{
    class Server {
        ClientHandler clientHandler;
    public:
        Server(ClientHandler c) : clientHandler(c) {
        }
        virtual void open(int port);
        virtual void stop();

        virtual ~Server() {
            delete (clientHandler);
        }
    };
}


#endif //SECONDMIILESTONE_SERVER_SIDE_H
