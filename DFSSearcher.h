//
// Created by davidregev on 14/01/19.
//

#ifndef SECONDMIILESTONE_DFSSEARCHER_H
#define SECONDMIILESTONE_DFSSEARCHER_H

#include <vector>
#include "Searcher.h"
#include "StackDB.h"

template<class T>
class DFSSearcher : public TraceBackSearcher<T> {
private:
    StackDB<T> stack;
public:
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        State<T> *processState;

        stack.pushToOpen(init);

        // initial to 0 before processing
        this->numOfNodesEvaluated = 0;

        // if init is goal we will find it out in the first iteration of the while loop
        while (!stack.emptyOpen()) {
            this->numOfNodesEvaluated++;
            // pop out a state to process from the stack
            processState = stack.popFromOpen();

            // check if the current state is the goal state
            if (*processState == *goal) {
                vector<State<T> *> output = this->backTrace(init, processState);
                this->clearAll(output,&stack);
                return output;
            }

            // check if the current state was already processed
            if (!stack.isExistVector(processState)) {
                stack.pushToClosed(processState);

                vector<State<T>*> successors = searchable->getAllPossibleState(processState);

                // insert all the successors of the processed state to the stack
                for (int i = 0; i < successors.size(); ++i) {
                    stack.pushToOpen(successors[i]);
                }
            }else {
                delete (processState);
            }
        }
        vector<State<T> *> emptyVector;
        this->clearAll(emptyVector,&stack);
        return emptyVector;
    }


};


#endif //SECONDMIILESTONE_DFSSEARCHER_H
