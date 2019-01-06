//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SERVER_SIDE_H
#define SECONDMIILESTONE_SERVER_SIDE_H


#include "ClientHandler.h"

namespace server_side{
    class Server {
        void open(int port, ClientHandler c);
        void stop();
    };
}


#endif //SECONDMIILESTONE_SERVER_SIDE_H
