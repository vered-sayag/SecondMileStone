//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_QUEUESEARCHER_H
#define SECONDMIILESTONE_QUEUESEARCHER_H

#include <queue>
#include <vector>
#include "Searcher.h"
template <class T, class Solution>
class QueueSearcher : public Searcher<T, Solution> {
protected:
    queue<State<T>*> openList;
    vector<State<T>*> closedList;

public:
    virtual State<T>* pop() {
        State<T>* temp = openList.front();
        openList.pop();
        return temp;
    }

    virtual State<T>* top() {
        return openList.front();
    }

    virtual unsigned long size() {
        openList.size();
    }

    virtual void push(State<T>* state) {
        openList.push(state);
    }

    virtual bool empty() {
        return openList.empty();
    }

    virtual bool isExistQueue(State<T>* state) {
        vector<State<T>*> states;
        State<T> *tempState;
        bool exist = false;

        // pop all states to a vector and checking if the state exists in pq
        while (!empty()) {
            tempState = pop();
            states.push_back(tempState);
        }
        // check if the state exists in the vector
        for (int i = 0; i < states.size(); ++i) {
            push(states[i]);
            if (states[i] == state) {
                exist = true;
            }
        }
        return exist;
    }

    virtual bool isExistVector(State<T>* state) {
        for ( int i =0; i<closedList.size(); i++){
            if (*closedList[i] == *state) {
                return true;
            }
        }
        return false;
    }
};


#endif //SECONDMIILESTONE_QUEUESEARCHER_H
