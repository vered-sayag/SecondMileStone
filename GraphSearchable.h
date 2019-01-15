//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_GRAPHSEARCHABLE_H
#define SECONDMIILESTONE_GRAPHSEARCHABLE_H

#include <vector>
#include "Searchable.h"
#include "State.h"

class GraphSearchable : public Searchable< pair <int, int> > {
    vector< vector< double > > matrix;
    State< pair< int, int> >* init;
    State< pair< int, int> >* goal;


public:
    GraphSearchable(const vector<vector<double>> &table);

    State< pair<int, int> >* getInitialState() {
        return init;
    }

    State< pair<int, int> >* getGoalState() {
        return goal;
    }

    vector< State <pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *s);

    vector< State <pair<int, int>> *> getAllPossibleState(State<pair<int, int>> *cur, State<pair<int, int>> *target);
};


#endif //SECONDMIILESTONE_GRAPHSEARCHABLE_H
