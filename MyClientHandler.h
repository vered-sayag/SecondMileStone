//
// Created by vered on 1/10/19.
//

#ifndef SECONDMIILESTONE_MYCLIENTHANDLER_H
#define SECONDMIILESTONE_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

namespace server_side {
    class MyClientHandler : public ClientHandler {
        Solver<string,vector<vector<int>>> *solver;
        CacheManager *cacheManager;

        vector <int> splitByComma(string str);

    public:
        MyClientHandler(Solver<string,vector<vector<int>>> *s, CacheManager *c) : solver(s), cacheManager(c) {}

        virtual void handleClient(int socket) ;

        ~MyClientHandler(){
            delete (solver);
            delete (cacheManager);
        }
    };
}


#endif //SECONDMIILESTONE_MYCLIENTHANDLER_H
