//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_QUEUESEARCHER_H
#define SECONDMIILESTONE_QUEUESEARCHER_H

#include <queue>
#include <vector>
#include "Searcher.h"
#include "DBtoSearcher.h"
template <class T>
class QueueDB: public DBtoSearcher<T>{
private:
    queue<State<T>*> openList;

public:

    virtual void pushToOpen(State<T>* state) {
        openList.push(state);
    }



    virtual State<T>* popFromOpen() {
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

    virtual bool emptyOpen() {
        return openList.empty();
    }


    virtual bool isExistQueue(State<T>* state) {
        vector<State<T>*> states;
        State<T> *tempState;
        bool exist = false;

        // pop all states to a vector and checking if the state exists in pq
        while (!emptyOpen()) {
            tempState = popFromOpen();
            states.push_back(tempState);
        }
        // check if the state exists in the vector
        for (int i = 0; i < states.size(); ++i) {
            pushToOpen(states[i]);
            if (states[i] == state) {
                exist = true;
            }
        }
        return exist;
    }

};


#endif //SECONDMIILESTONE_QUEUESEARCHER_H
