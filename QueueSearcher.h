//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_QUEUESEARCHER_H
#define SECONDMIILESTONE_QUEUESEARCHER_H

#include <queue>
#include <vector>
#include "Searcher.h"
template <class Solution,class T>
class QueueSearcher : public Searcher<Solution, T> {
protected:
    queue<State<T>*> openList;
    vector<State<T>*> closedList;

public:
    State<T>* pop() {
        return openList.pop();
    }

    State<T>* top() {
        openList.top();
    }

    unsigned long size() {
        openList.size();
    }

    void push(State<T>* state) {
        openList.push(state);
    }

    bool empty() {
        return openList.empty();
    }

    bool isExistQueue(State<T>* state) {
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

    bool isExistVector(State<T>* state) {
        return find(closedList.begin(), closedList.end(), state) != closedList.end());
    }
};


#endif //SECONDMIILESTONE_QUEUESEARCHER_H
