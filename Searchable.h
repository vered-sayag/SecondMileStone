//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_SEARCHABLE_H
#define SECONDMIILESTONE_SEARCHABLE_H

#include <vector>
#include "State.h"

template<class T>
class Searchable {

public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual vector< State<T> *> getAllPossibleState(State<T> *s) = 0;
    virtual ~Searchable(){}
};


#endif //SECONDMIILESTONE_SEARCHABLE_H
