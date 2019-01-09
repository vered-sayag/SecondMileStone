//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_SOLVER_H
#define SECONDMIILESTONE_SOLVER_H
namespace server_side {
    template<class S, class P>
    class Solver {
    public:
        virtual S solve(P p) = 0;
    };
}

#endif //SECONDMIILESTONE_SOLVER_H
