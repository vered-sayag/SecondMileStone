//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_MYTESTCLIENTHANDLER_H
#define SECONDMIILESTONE_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler {
    Solver solver;

public:
    MyTestClientHandler(Solver s) : solver(s) {}
};


#endif //SECONDMIILESTONE_MYTESTCLIENTHANDLER_H
