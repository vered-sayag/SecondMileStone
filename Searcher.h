//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_SEARCHER_H
#define SECONDMIILESTONE_SEARCHER_H

#include "Searchable.h"

template <class Solution>
class Searcher {
public:
    virtual Solution search(Searchable searchable) = 0;
    virtual int getNumOfNodesEvaluated() = 0;
};


#endif //SECONDMIILESTONE_SEARCHER_H
