//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_CACHEMANAGER_H
#define SECONDMIILESTONE_CACHEMANAGER_H


#include "Problem.h"
#include "Solution.h"

class CacheManager {
    bool isExist(Problem p);
    void pushSolution(Solution s, Problem p);
    Solution popSolution(Problem p);
};


#endif //SECONDMIILESTONE_CACHEMANAGER_H
