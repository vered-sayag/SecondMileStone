//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_STACKSEARCHER_H
#define SECONDMIILESTONE_STACKSEARCHER_H

#include <stack>
#include <vector>
#include "State.h"
#include "Searcher.h"
#include "DBtoSearcher.h"

template <class T>
class StackDB : public DBtoSearcher<T>{
private:
    stack<State<T>*> openList;

public:

    virtual State<T>* popFromOpen() {
        State<T>* temp = openList.top();
        openList.pop();
        return temp;
    }


    virtual State<T>* top() {
        return openList.top();
    }

    virtual bool emptyOpen() {
        return openList.empty();
    }


    virtual void pushToOpen(State<T>* state) {
        openList.push(state);
    }



};


#endif //SECONDMIILESTONE_STACKSEARCHER_H
