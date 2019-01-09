//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_CACHEMANAGER_H
#define SECONDMIILESTONE_CACHEMANAGER_H

#include <string>
using namespace std;
namespace server_side {
    class CacheManager {
    public:
        virtual bool isExist(string p) = 0;

        virtual void pushSolution(string s, string p) = 0;

        virtual string popSolution(string p) = 0;
    };
}


#endif //SECONDMIILESTONE_CACHEMANAGER_H
