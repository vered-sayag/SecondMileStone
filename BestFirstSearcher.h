//
// Created by davidregev on 10/01/19.
//


#ifndef SECONDMIILESTONE_BESTFIRSTSEARCHER_H
#define SECONDMIILESTONE_BESTFIRSTSEARCHER_H

#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "PriorityQueueDB.h"
#include "TraceBackSearcher.h"

template<class T>
class BestFirstSearcher : public TraceBackSearcher<T>  {
private:
    PriorityQueueDB<T> pq;
public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        this->numOfNodesEvaluated = 0;
        //adding the initalState to the open list.
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        pq.pushToOpen(init);

        // initial to 0 before processing

        while (!pq.emptyOpen()) {
            this->numOfNodesEvaluated++;
            //start develop the node
            State<T> *minState = pq.popFromOpen();

            pq.pushToClosed(minState);
            //if we got to the goal
            if (*minState == *goal) {
                vector<State<T> *> output = this->backTrace(init, minState);
                this->clearAll(output,&pq);
                return output;
            }


            vector<State<T> *> successors = searchable->getAllPossibleState(minState);
            for (int i = 0; i < successors.size(); ++i) {

                if (!pq.isExistQueue(successors[i]) && !pq.isExistVector(successors[i])) {
                    pq.pushToOpen(successors[i]);
                } else if (!pq.isExistVector(successors[i])) {

                    State<T> *item = pq.find(successors[i]);

                    if (successors[i]->getCost() < item->getCost()) {
                        pq.erase(item);
                        pq.pushToOpen(successors[i]);

                    }else{
                        delete (successors[i]);
                    }
                } else {
                    delete (successors[i]);
                }
            }
        }

        vector<State<T> *> emptyVector;
        this->clearAll(emptyVector,&pq);
        return emptyVector;
    }

};
#endif //SECONDMIILESTONE_BESTFIRSTSEARCHER_H