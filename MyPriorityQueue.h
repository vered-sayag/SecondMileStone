//
// Created by vered on 1/13/19.
//

#ifndef SECONDMIILESTONE_MYPRIORITYQUEUE_H
#define SECONDMIILESTONE_MYPRIORITYQUEUE_H

#include <queue>
#include "State.h"

using namespace std;

class MyPriorityQueue {
    priority_queue<double> pq;

public:
    void setState(State<pair<int, int>> s, double value);

};


#endif //SECONDMIILESTONE_MYPRIORITYQUEUE_H
