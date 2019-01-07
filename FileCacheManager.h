//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_FILECACHEMANAGER_H
#define SECONDMIILESTONE_FILECACHEMANAGER_H


#include "CacheManager.h"

class FileCacheManager : public CacheManager {
    virtual bool isExist(string p);
    virtual void pushSolution(string s, string p);
    virtual string popSolution(string p);
};


#endif //SECONDMIILESTONE_FILECACHEMANAGER_H
