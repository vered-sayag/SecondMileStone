//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_FILECACHEMANAGER_H
#define SECONDMIILESTONE_FILECACHEMANAGER_H

#include <map>
#include "CacheManager.h"
namespace server_side {
    class FileCacheManager : public CacheManager {
        map<string, string> problemSolutionMap;
        string myFileName;
        pthread_mutex_t mutex;
    public:
        FileCacheManager(string fileName);

        virtual bool isExist(string p);

        virtual void pushSolution(string s, string p);

        virtual string popSolution(string p);

    };
}


#endif //SECONDMIILESTONE_FILECACHEMANAGER_H
