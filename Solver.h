//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SOLVER_H
#define SECONDMIILESTONE_SOLVER_H
namespace server_side {
    template<class Solution, class Problem>
    class Solver {
    public:
        virtual Solution solve(Problem problem) = 0;
    };
}

#endif //SECONDMIILESTONE_SOLVER_H
