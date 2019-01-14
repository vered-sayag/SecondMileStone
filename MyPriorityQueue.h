//
// Created by vered on 1/13/19.
//

#ifndef SECONDMIILESTONE_MYPRIORITYQUEUE_H
#define SECONDMIILESTONE_MYPRIORITYQUEUE_H

#define STATE State<double>

#include <queue>
#include "State.h"

using namespace std;


class CompareState {
public:
    bool operator()(STATE cmp, STATE other) {
        return cmp.getCost() > other.getCost();
    }
};

class MyPriorityQueue {
    priority_queue<double, vector<STATE>, CompareState>  pq;

public:
    void push(STATE state) {
        pq.push(state);
    }

    STATE top() {
        return pq.top();
    }

    STATE pop() {
        STATE temp = top();
        pq.pop();
        return temp;
    }

    bool empty() {
        return pq.empty();
    }

    unsigned long size() {
        return pq.size();
    }

    void setState(State<pair<int, int>> s, double value);

};


#endif //SECONDMIILESTONE_MYPRIORITYQUEUE_H
