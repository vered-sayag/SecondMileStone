//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_SEARCHER_H
#define SECONDMIILESTONE_SEARCHER_H

#include "Searchable.h"

template <class Problem, class Solution>
class Searcher {
protected:
    int numOfNodesEvaluated;

public:
    virtual Solution search(Searchable<Problem> searchable) = 0;
    virtual int getNumOfNodesEvaluated() = 0;
};


#endif //SECONDMIILESTONE_SEARCHER_H
