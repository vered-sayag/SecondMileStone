//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_BFSSEARCHER_H
#define SECONDMIILESTONE_BFSSEARCHER_H

#include <string>
#include "Searcher.h"
#include "Searchable.h"

template <class T>
class BFSSearcher : public Searcher<T, string> {
public:
    string search(Searchable<T> searchable) {

    }

    int getNumOfNodesEvaluated() {
        return this->numOfNodesEvaluated;
    }
};


#endif //SECONDMIILESTONE_BFSSEARCHER_H
