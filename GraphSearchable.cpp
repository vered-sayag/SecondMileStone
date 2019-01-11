//
// Created by davidregev on 10/01/19.
//

#include "GraphSearchable.h"

GraphSearchable::GraphSearchable(vector < double > < vector > table) {
    State< int[2] > tempState, init, goal;

    // initializing the list of states
    for (unsigned int row = 0; row < table.size() - 1; ++row) {
        for (unsigned int column; column < table[row].size(); ++column) {
            int[2] state = {row, column};
            double cost = table[row][column];
            tempState = new State < int[2] >(state, cost, nullptr);
            this.states.emplace_back(tempState);
            this.matrix[i][j] = tempState;
        }
    }

    // initializing the init and goal states
    vector< double > startEnd = table[table.size()];
    int[2] start = { startEnd[0], startEnd[1] };
    int[2] end = { startEnd[2], startEnd[3] };

    double startCost = table[start[0]][start[1]];
    double endCost = table[end[0]][end[1]];

    this.init = new State< int[2] > (start, startCost, nullptr);
    this.goal = new State< int[2] > (end, endCost, nullptr);
}