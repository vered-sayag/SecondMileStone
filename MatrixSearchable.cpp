//
// Created by davidregev on 10/01/19.
//

#include <cmath>
#include "MatrixSearchable.h"

MatrixSearchable::MatrixSearchable(const vector<vector<double> > &table) {
    // initialize the matrix
    matrix = table;

    // initializing the init and goal states
    vector<double> start = table[table.size() - 2];
    vector<double> end = table[table.size() - 1];
    pair<int, int> initial = {(int) start[0], (int) start[1]};
    pair<int, int> goaler = {(int) end[0], (int) end[1]};

    double startCost = table[initial.first][initial.second];
    double endCost = table[goaler.first][goaler.second];

    init = new State<pair<int, int>>(initial, startCost, nullptr);
    goal = new State<pair<int, int>>(goaler, endCost, nullptr);
}

vector<State<pair<int, int>> *> MatrixSearchable::getAllPossibleState(State<pair<int, int>> *s) {
    unsigned long numOfRows = matrix.size() - 2;
    unsigned long numOfColumns = matrix[1].size();

    vector<State<pair<int, int> > *> adj;

    // validation checking
    int row = s->getState().first;
    int column = s->getState().second;

    // s is not in the last row
    if (row + 1 < numOfRows ) {
        pair<int, int> tempPair = {row + 1, column};
        double tempCost = matrix[row + 1][column] ;
        if (tempCost != -1) {

            adj.push_back(new State<pair<int, int>>(tempPair, tempCost+ s->getCost(), s));
        }
    }

    // s is not in the first row
    if (row - 1 >= 0) {
        pair<int, int> tempPair = {row - 1, column};
        double tempCost = matrix[row - 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost+ s->getCost(), s));
        }
    }

    // s is not in the first column
    if (column - 1 >= 0) {
        pair<int, int> tempPair = {row, column - 1};
        double tempCost = matrix[row][column - 1];
        if (tempCost != -1) {

            adj.push_back(new State<pair<int, int>>(tempPair, tempCost+ s->getCost(), s));
        }
    }

    // s is not in the last column
    if (column + 1 < numOfColumns) {
        pair<int, int> tempPair = {row, column + 1};
        double tempCost = matrix[row][column + 1];
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost+ s->getCost(), s));
        }
    }

    return adj;
}

vector<State<pair<int, int>> *> MatrixSearchable::getAllPossibleState(State<pair<int, int>> *cur, State<pair<int, int>> *target) {
    unsigned long numOfRows = matrix.size() - 2;
    unsigned long numOfColumns = matrix[1].size();

    vector<State<pair<int, int> > *> adj;

    // validation checking
    int row = cur->getState().first;
    int column = cur->getState().second;
    int curHeuristic = abs(goal->getState().first - row) + abs(goal->getState().second - column);
    int nextHeuristic, combinedHeuristic;

    // s is not in the last row
    if (row + 1 < numOfRows ) {
        nextHeuristic =  abs(goal->getState().first - row + 1) + abs(goal->getState().second - column);
        combinedHeuristic = abs(nextHeuristic - curHeuristic);
        pair<int, int> tempPair = {row + 1, column};
        double tempCost = matrix[row + 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost + cur->getCost() + combinedHeuristic, cur));
        }
    }

    // s is not in the first row
    if (row - 1 >= 0) {
        nextHeuristic =  abs(goal->getState().first - row - 1) + abs(goal->getState().second - column);
        combinedHeuristic = abs(nextHeuristic - curHeuristic);
        pair<int, int> tempPair = {row - 1, column};
        double tempCost = matrix[row - 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost + cur->getCost() + combinedHeuristic, cur));
        }
    }

    // s is not in the first column
    if (column - 1 >= 0) {
        nextHeuristic =  abs(goal->getState().first - row) + abs(goal->getState().second - column - 1);
        combinedHeuristic = abs(nextHeuristic - curHeuristic);
        pair<int, int> tempPair = {row, column - 1};
        double tempCost = matrix[row][column - 1];
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost + cur->getCost() + combinedHeuristic, cur));
        }
    }

    // s is not in the last column
    if (column + 1 < numOfColumns) {
        nextHeuristic =  abs(goal->getState().first - row) + abs(goal->getState().second - column + 1);
        combinedHeuristic = abs(nextHeuristic - curHeuristic);
        pair<int, int> tempPair = {row, column + 1};
        double tempCost = matrix[row][column + 1];
        if (tempCost != -1) {
            adj.push_back(new State<pair<int, int>>(tempPair, tempCost + cur->getCost() + combinedHeuristic, cur));
        }
    }

    return adj;
}