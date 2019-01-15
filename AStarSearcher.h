//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_ASTARSEARCHER_H
#define SECONDMIILESTONE_ASTARSEARCHER_H


#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "PriorityQueueDB.h"
#include "TraceBackSearcher.h"

template<class T>
class AStarSearcher : public TraceBackSearcher<T> {
    PriorityQueueDB<T> pqs;

public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        this->numOfNodesEvaluated = 0;
        //adding the initalState to the open list.
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        pqs.pushToOpen(init);
        while (!pqs.emptyOpen()) {
            //start develop the node
            State<T> *minState = pqs.popFromOpen();
            this->numOfNodesEvaluated++;
            pqs.pushToClosed(minState);
            //if we got to the goal
            if (*minState == *goal) {
                vector<State<T> *> output = this->backTrace(init, minState);
                this->clearAll(output,&pqs);
                return output;
            }

            vector<State<T> *> successors = searchable->getAllPossibleState(minState, goal);
            for (int i = 0; i < successors.size(); ++i) {
                if (!pqs.isExistQueue(successors[i]) && !pqs.isExistVector(successors[i])) {
                    pqs.pushToOpen(successors[i]);
                } else if (!pqs.isExistVector(successors[i])) {
                    State<T> *item = pqs.find(successors[i]);
                    if (successors[i]->getCost() < item->getCost()) {
                        pqs.erase(item);
                        pqs.pushToOpen(successors[i]);
                    } else {
                        delete (successors[i]);
                    }
                } else {
                    delete (successors[i]);
                }
            }
        }

        vector<State<T> *> emptyVector;
        this->clearAll(emptyVector,&pqs);
        return emptyVector;
    }


};

#endif //SECONDMIILESTONE_ASTARSEARCHER_H
