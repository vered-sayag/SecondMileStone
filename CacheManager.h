//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_CACHEMANAGER_H
#define SECONDMIILESTONE_CACHEMANAGER_H

class CacheManager {
public:
    virtual bool isExist(string p);
    virtual void pushSolution(string s, string p);
    virtual string popSolution(string p);
};


#endif //SECONDMIILESTONE_CACHEMANAGER_H
