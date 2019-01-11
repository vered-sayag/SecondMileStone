//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_GRAPHSEARCHABLE_H
#define SECONDMIILESTONE_GRAPHSEARCHABLE_H

#include <vector>
#include "Searchable.h"
#include "State.h"

class GraphSearchable : public Searchable {
public:
    GraphSearchable(vector<vector<double>> table) {}
    State getInitialState() {}
    State getGoalState() {}
    State getAllPossibleState() {}
};


#endif //SECONDMIILESTONE_GRAPHSEARCHABLE_H
