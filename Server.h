//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SERVER_SIDE_H
#define SECONDMIILESTONE_SERVER_SIDE_H


#include "ClientHandler.h"

namespace server_side{
    class Server {

    public:

        virtual void open(int port,ClientHandler* c)=0;
        virtual void stop()=0;

        virtual ~Server() {

        }
    };
}


#endif //SECONDMIILESTONE_SERVER_SIDE_H
