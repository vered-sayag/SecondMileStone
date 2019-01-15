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

        openList.push(init);

        while(!empty()) {
            proccessState = openList.pop();

            if(*proccessState == *goal) {
                return searchable.backTrace(init, proccessState);
            }

            vector<State<T>*> successors = searchable->getAllPossibleState(proccessState);

            for (int i = 0; i < successors.size(); ++i) {
                // not to proccess the father again
                if(*successors[i] == *proccessState) {
                    continue;
                }

                // if the successor is in the closed list
                if (!isExistsVector(successors[i])) {

                    // set the ancestor
                    successors[i].setCameFrom(proccessState);

                    // insert to the queue
                    openList.push(successors[i]);

                    // insert the successor to the closed list
                    closedList.push_back(successors[i]);
                }
            }
        }
        vector<State<T> *> emptyVector;
        return emptyVector;
    }
};


#endif //SECONDMIILESTONE_BFSSEARCHER_H
