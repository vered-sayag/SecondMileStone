//
// Created by davidregev on 10/01/19.
//

#include "GraphSearchable.h"

GraphSearchable::GraphSearchable(vector <  vector < double > > table) {
    // initialize the matrix
    matrix = table;

    // initializing the init and goal states
    vector< double > start = table[table.size() - 2];
    vector< double > end = table[table.size() - 1];
    pair <int, int> initial = { (int)start[0], (int)start[1] };
    pair <int, int> goaler = { (int)end[0], (int)end[1] };

    double startCost = table[initial.first][initial.second];
    double endCost = table[goaler.first][goaler.second];

    init (initial, startCost, nullptr);
    goal (goaler, endCost, nullptr);
}

vector<State<pair<int, int>>> GraphSearchable::getAllPossibleState(State<pair<int, int>> s) {
    unsigned long numOfRows = matrix.size() - 2;
    unsigned long numOfColumns = matrix[1].size();

    vector< State< pair<int, int> > > adj;

    // validation checking
    int row = s.getState().first;
    int column = s.getState().second;

    // s is not in the last row
    if (row + 1 < numOfRows - 1) {
        pair< int, int> tempPair = {row + 1, column};
        double tempCost = matrix[row + 1][column];
        if (tempCost != -1) {
            State< pair<int, int> > tempState (tempPair, tempCost, s);
            adj.push_back(tempState);
        }
    }

    // s is not in the first row
    if (row - 1 >= 0) {
        pair< int, int> tempPair = {row - 1, column};
        double tempCost = matrix[row - 1][column];
        if (tempCost != -1) {
            State< pair<int, int> > tempState (tempPair, tempCost, s);
            adj.push_back(tempState);
        }
    }

    // s is not in the first column
    if (column - 1 >= 0) {
        pair< int, int> tempPair = {row, column - 1};
        double tempCost = matrix[row][column - 1];
        if (tempCost != -1) {
            State< pair<int, int> > tempState (tempPair, tempCost, s);
            adj.push_back(tempState);
        }
    }

    // s is not in the last column
    if (column + 1 < numOfColumns - 1) {
        pair< int, int> tempPair = {row, column + 1};
        double tempCost = matrix[row][column + 1];
        if (tempCost != -1) {
            State< pair<int, int> > tempState (tempPair, tempCost, s);
            adj.push_back(tempState);
        }
    }

    return adj;
}