//
// Created by vered on 1/13/19.
//

#ifndef SECONDMIILESTONE_MYPRIORITYQUEUE_H
#define SECONDMIILESTONE_MYPRIORITYQUEUE_H

#include <queue>
#include "State.h"

using namespace std;

template <class T>
class CompareState {
public:
    bool operator()(State<T> *cmp, State<T>* other) {
        return cmp->getCost() > other->getCost();
    }
};

template <class T>
class MyPriorityQueue {
    priority_queue<State<T>*, vector<State<T>*>, CompareState<T>>  pq;

public:
    void push(State<T>* state) {
        pq.push(state);
    }

    State<T>* top() {
        return pq.top();
    }

    State<T>* pop() {
        State<T>* temp = top();
        pq.pop();
        return temp;
    }

    bool empty() {
        return pq.empty();
    }

    unsigned long size() {
        return pq.size();
    }

//    void setState(State<T>* state, double cost) {
//        State<T>* tempState = find(State<T>);
//        tempState->setCost(cost);
//        push(tempState);
//    }

    State<T>* find(State<T>* state) {
        vector<State<T>*> states;
        State<T> *tempState;
        State<T> *retState = nullptr;

        // pop all states to a vector and checking if the state exists in pq
        while (!empty()) {
            tempState = pop();
            states.push_back(tempState);
            if (*tempState == *state) {
                retState = tempState;
                break;
            }
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            push(states[i]);
        }
        return retState;
    }

    void erase(State<T>* state) {
        vector<State<T>*> states;
        State<T> *tempState;

        // pop all states to a vector and checking if the state exists in pq
        while (!empty()) {
            tempState = pop();
            if (tempState == state) {
                delete (tempState);
                break;
            }
            states.push_back(tempState);
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            push(states[i]);
        }
    }

    bool isExist(State<T>* state) {
        vector<State<T>*> states;
        State<T> *tempState;
        bool exist = false;

        // pop all states to a vector and checking if the state exists in pq
        while (!empty()) {
            tempState = pop();
            states.push_back(tempState);
            if (*tempState == *state) {
                exist = true;
                break;
            }
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            push(states[i]);
        }
        return exist;
    }

};


#endif //SECONDMIILESTONE_MYPRIORITYQUEUE_H
