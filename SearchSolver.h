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
#include "Searchable.h"
#include "MatrixSearchable.h"
#include "BestFirstSearcher.h"
#include "AStarSearcher.h"
#include "BFSSearcher.h"
#include "DFSSearcher.h"

using namespace std;
namespace server_side {
    class SearchSolver : public Solver<string, vector<vector<double >>> {
    public:

        string solve(vector<vector<double >> p) {
            Searcher<pair<int, int>, vector<State<pair<int, int> > *>> *searcher = new AStarSearcher<pair<int, int>>();
            Searchable<pair<int, int>> *searchable = new MatrixSearchable(p);
            vector<State<pair<int, int> > *> solution = searcher->search(searchable);

           // cout << searcher->getNumOfNodesEvaluated() << endl;

            if (solution.size() == 0) {
                return "-1";
            }

            //int cost = 0;

            string ans = "";

            for (int i = 0; i < solution.size() - 1; i++) {

                pair<int, int> thisState = solution[i]->getState();
                pair<int, int> nextState = solution[i + 1]->getState();

                //cost += p[thisState.first][thisState.second];
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
                    //cost += p[nextState.first][nextState.second];

                    //cout << cost << endl;

                    delete (solution[i + 1]);
                }

            }


            //cout << ans << endl;

            delete (searcher);
            delete (searchable);

            return ans;
        }

        ~SearchSolver() {

        }
    };

}
#endif //SECONDMIILESTONE_SEARCHSOLVER_H
