//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_MYSERIALSERVER_H
#define SECONDMIILESTONE_MYSERIALSERVER_H

#include <list>
#include <vector>
#include "Server.h"
#include "ClientHandler.h"
#include "MyTCPserver.h"

using namespace server_side;
namespace server_side {
    class MySerialServer : public MyTCPserver {

    protected:

        virtual void unique(int socket, bool *shouldStop, ClientHandler *client);

    };


}


#endif //SECONDMIILESTONE_MYSERIALSERVER_H
