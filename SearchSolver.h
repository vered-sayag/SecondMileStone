//
// Created by vered on 1/15/19.
//

#ifndef SECONDMIILESTONE_SEARCHSOLVER_H
#define SECONDMIILESTONE_SEARCHSOLVER_H

#include <string>
#include <vector>
#include "Solver.h"
#include "Searcher.h"
#include "State.h"
#include "BestFirstSearcher.h"
#include "Searchable.h"
#include "GraphSearchable.h"

using namespace std;
namespace server_side {
    class SearchSolver : public Solver<string, vector<vector<double >>> {
    public:

        string solve(vector<vector<double >> p) {
            Searcher<pair<int, int>, vector<State<pair<int, int> > *>> *searcher = new BFSSearcher<pair<int, int>>();
            Searchable<pair<int, int>> *searchable = new GraphSearchable(p);
            vector<State<pair<int, int> > *> solution = searcher->search(searchable);

            if (solution.size() == 0) {
                return "-1";
            }

            string ans = "";

            for (int i = 0; i < solution.size() - 1; i++) {

                pair<int, int> thisState = solution[i]->getState();
                pair<int, int> nextState = solution[i + 1]->getState();

                //}Right, Left, Down, Up }

                if (thisState.first > nextState.first) {
                    ans = ans + "Up";
                } else if (thisState.first < nextState.first) {
                    ans = ans + "Down";
                } else if (thisState.second > nextState.second) {
                    ans = ans + "Left";
                } else if (thisState.second < nextState.second) {
                    ans = ans + "Right";
                }

                delete (solution[i]);
                if (i != solution.size() - 2) {
                    ans = ans + ",";
                } else {
                    delete (solution[i + 1]);
                }

            }
            delete (searcher);
            delete (searchable);

            return ans;
        }

        ~SearchSolver() {

        }
    };

}
#endif //SECONDMIILESTONE_SEARCHSOLVER_H
