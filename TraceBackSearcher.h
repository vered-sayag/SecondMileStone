//
// Created by vered on 1/15/19.
//

#ifndef SECONDMIILESTONE_TRACEBACKSEARCHER_H
#define SECONDMIILESTONE_TRACEBACKSEARCHER_H

#include "Searcher.h"
#include "DBtoSearcher.h"
template<class T>
class TraceBackSearcher : public Searcher<T, vector<State<T> *>>{
protected:
    virtual vector<State<T> *> backTrace(State<T> *init, State<T> *goal) {
        vector<State<T> *> trace;
        vector<State<T> *> output;
        State<T> *tempState = goal;

        while (!(*tempState == *init)) {
            trace.push_back(tempState);
            tempState = tempState->getCameFrom();
        }
        trace.push_back(init);

        for (unsigned long i = trace.size(); i > 0; i--) {
            output.push_back(trace[i-1]);
        }
        return output;
    }


    virtual void clearAll(vector<State<T> *> output,DBtoSearcher<T>* DB) {
        State<T> *temp;
        while (!DB->emptyOpen()) {
            delete (DB->popFromOpen());
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
#endif //SECONDMIILESTONE_TRACEBACKSEARCHER_H
