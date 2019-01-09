//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_MYTESTCLIENTHANDLER_H
#define SECONDMIILESTONE_MYTESTCLIENTHANDLER_H
#define END_MESSAGE "end"

#include <sys/socket.h>
#include <unistd.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
namespace server_side {
    class MyTestClientHandler : public ClientHandler {
        Solver<string, string> *solver;
        CacheManager *cacheManager;
    public:
        MyTestClientHandler(Solver<string, string> *s, CacheManager *c) : solver(s), cacheManager(c) {}

        virtual void handleClient(int socket) ;

        ~MyTestClientHandler(){
            delete (solver);
            delete (cacheManager);
        }
    };

}
#endif //SECONDMIILESTONE_MYTESTCLIENTHANDLER_H
