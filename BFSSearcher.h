//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_BFSSEARCHER_H
#define SECONDMIILESTONE_BFSSEARCHER_H

#include <queue>
#include "State.h"
#include "QueueSearcher.h"

using namespace std;

template <class T>
class BFSSearcher : public QueueSearcher<T, vector<State<T> *>> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        State<T> *proccessState;

        this->push(init);

        while(!this->empty()) {
            proccessState = this->pop();

            if(*proccessState == *goal) {
                return backTrace(init, proccessState);
            }

            vector<State<T>*> successors = searchable->getAllPossibleState(proccessState);

            for (int i = 0; i < successors.size(); ++i) {
                // not to proccess the father again
                if(*successors[i] == *proccessState) {
                    continue;
                }

                // if the successor is in the closed list
                if (!this->isExistVector(successors[i])) {

                    // set the ancestor
//                    successors[i]->setCameFrom(proccessState);

                    // insert to the queue
                    this->openList.push(successors[i]);

                    // insert the successor to the closed list
                    this->closedList.push_back(successors[i]);
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

        for (int i = trace.size() - 1; i >= 0; i--) {
            output.push_back(trace[i]);
        }
        return output;
    }
};


#endif //SECONDMIILESTONE_BFSSEARCHER_H
