//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_CLIENTHANDLER_H
#define SECONDMIILESTONE_CLIENTHANDLER_H

#include <ios>

using namespace std;

namespace server_side {
    class ClientHandler {

    public:
        virtual void handleClient(int socket) = 0;
        virtual ~ClientHandler(){}
    };
}


#endif //SECONDMIILESTONE_CLIENTHANDLER_H
