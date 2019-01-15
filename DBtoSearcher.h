//
// Created by vered on 1/15/19.
//

#ifndef SECONDMIILESTONE_DBTOSEARCHER_H
#define SECONDMIILESTONE_DBTOSEARCHER_H

#include "State.h"
#include <vector>

using namespace std;

template<class T>
class DBtoSearcher {
protected:
    vector<State<T> *> closedList;

public:

    virtual State<T> *popFromOpen() = 0;

    virtual State<T> *popFromClosed() {
        State<T> *temp = closedList.back();
        closedList.pop_back();
        return temp;
    }


    virtual bool emptyOpen() = 0;

    virtual bool emptyClosed() {
        return closedList.empty();
    }

    virtual void pushToOpen(State<T> *state) = 0;

    virtual void pushToClosed(State<T> *state) {
        closedList.push_back(state);
    }

    virtual bool isExistVector(State<T> *state) {
        for (int i = 0; i < closedList.size(); i++) {
            if (*closedList[i] == *state) {
                return true;
            }
        }
        return false;
    }

};

#endif //SECONDMIILESTONE_DBTOSEARCHER_H
