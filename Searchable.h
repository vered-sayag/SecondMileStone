//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_SEARCHABLE_H
#define SECONDMIILESTONE_SEARCHABLE_H

#include "State.h"

class Searchable {
    State init;
    State goal;
    list<State> states;

public:
    virtual State getInitialState() = 0;
    virtual State getGoalState() = 0;
    virtual State getAllPossibleState() = 0;
};


#endif //SECONDMIILESTONE_SEARCHABLE_H
