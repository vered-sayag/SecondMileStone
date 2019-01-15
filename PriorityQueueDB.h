//
// Created by vered on 1/15/19.
//

#ifndef SECONDMIILESTONE_PRIORITYQUEUESEARCHER_H
#define SECONDMIILESTONE_PRIORITYQUEUESEARCHER_H

#include <vector>
#include "MyPriorityQueue.h"
#include "Searcher.h"
#include "State.h"
#include "DBtoSearcher.h"

template <class T>
class PriorityQueueDB : public  DBtoSearcher<T> {
private:
    MyPriorityQueue<T> openList;

public:
    virtual void pushToOpen(State<T>* state) {
        openList.push(state);
    }



    virtual State<T>* popFromOpen() {
        return openList.pop();
    }



    virtual State<T>* top() {
        return openList.top();
    }

    virtual unsigned long size() {
        openList.size();
    }

    virtual bool emptyOpen() {
        return openList.empty();
    }



    virtual bool isExistQueue(State<T>* state) {
        return openList.isExist(state);
    }


    virtual State<T>* find(State<T>* state) {
        openList.find(state);
    }

    virtual void erase(State<T>* state) {
        openList.erase(state);
    }
};


#endif //SECONDMIILESTONE_PRIORITYQUEUESEARCHER_H
