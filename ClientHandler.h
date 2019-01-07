//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_CLIENTHANDLER_H
#define SECONDMIILESTONE_CLIENTHANDLER_H

#include <ios>

using namespace std;

class ClientHandler {


public:
    virtual void handleClient(istream in, ostream out);
};


#endif //SECONDMIILESTONE_CLIENTHANDLER_H
