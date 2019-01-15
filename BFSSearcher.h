//
// Created by davidregev on 15/01/19.
//

#ifndef SECONDMIILESTONE_BFSSEARCHER_H
#define SECONDMIILESTONE_BFSSEARCHER_H


#include "State.h"
#include "Searcher.h"
#include "QueueDB.h"
#include "TraceBackSearcher.h"
using namespace std;

template <class T>
class BFSSearcher : public TraceBackSearcher<T>  {
private:
    QueueDB<T> queue;

public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        State<T> *processState;

        queue.pushToOpen(init);

        // initial to 0 before processing
        this->numOfNodesEvaluated = 0;

        // if init is goal we will find it out in the first iteration of the while loop

        while(!queue.emptyOpen()) {
            this->numOfNodesEvaluated++;
            processState = queue.popFromOpen();

            if(*processState == *goal) {
                vector<State<T> *> output = this->backTrace(init, processState);
                this->clearAll(output,&queue);
                return output;

            }

            vector<State<T>*> successors = searchable->getAllPossibleState(processState);

            for (int i = 0; i < successors.size(); ++i) {
                // not to process the father again

                // if the successor is in the closed list
                if (!queue.isExistVector(successors[i])) {

                    // insert to the queue
                    queue.pushToOpen(successors[i]);

                    // insert the successor to the closed list
                    queue.pushToClosed(successors[i]);
                }
            }
        }
        vector<State<T> *> emptyVector;
        this->clearAll(emptyVector,&queue);
        return emptyVector;
    }

    virtual void clearAll(vector<State<T> *> output,DBtoSearcher<T>* DB) {
        State<T> *temp;
        while (!DB->emptyOpen()) {
            State<T> * temp =DB->popFromOpen();
            if(!DB->isExistVector(temp)){
                delete (temp);
            }
        }
        while (!DB->emptyClosed()) {

            temp = DB->popFromClosed();

            for (int i = 0; i < output.size(); i++) {
                if (output[i] == temp) {
                    break;
                }
                if (i == output.size() - 1) {
                    delete (temp);
                }
            }

        }
    }
};


#endif //SECONDMIILESTONE_BFSSEARCHER_H
