//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_BFSSEARCHER_H
#define SECONDMIILESTONE_BFSSEARCHER_H

#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "MyPriorityQueue.h"

using namespace std;

template<class T>
class BestFirstSearcher : public Searcher<T, vector<State<T> *>> {
    MyPriorityQueue<T> openList;
    MyPriorityQueue<T> closedList;

public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        this->numOfNodesEvaluated = 0;
        //adding the initalState to the open list.
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        openList.push(init);
        while (!openList.empty()) {
            //start develop the node
            State<T> *minState = openList.pop();
            this->numOfNodesEvaluated++;
            closedList.push(minState);
            //if we got to the goal
            if (*minState == *goal) {
                return backTrace(init, minState);
            }

            vector<State<T> *> successors = searchable->getAllPossibleState(minState);
            for (int i = 0; i < successors.size(); ++i) {
                if (!openList.isExist(successors[i]) && !closedList.isExist(successors[i])) {
                    openList.push(successors[i]);
                } else if (!closedList.isExist(successors[i])) {
                    State<T> *item = openList.find(successors[i]);
                    if (successors[i]->getCost() < item->getCost()) {
                        openList.erase(item);
                        openList.push(successors[i]);
                    }
                }
            }
        }

        vector<State<T> *> emptyVector;
        return emptyVector;
    }

    vector<State<T> *> backTrace(State<T> *init, State<T> *goal) {
        vector<State<T> *> trace;
        vector<State<T> *> output;
        State<T> *tempState = goal;

        while (!(*tempState == *init)) {
            trace.push_back(tempState);
            tempState = tempState->getCameFrom();
        }
        trace.push_back(init);

        for (int i= trace.size()-1; i>=0;i--){
            output.push_back(trace[i]);
        }
        return output;
    }


    int getNumOfNodesEvaluated() {
        return this->numOfNodesEvaluated;
    }

};


#endif //SECONDMIILESTONE_BFSSEARCHER_H
