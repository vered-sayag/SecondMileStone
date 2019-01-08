//
// Created by vered on 08/01/19.
//

#ifndef SECONDMIILESTONE_STRINGREVERSE_H
#define SECONDMIILESTONE_STRINGREVERSE_H

#include "Solver.h"
#include "string"
 using namespace std;
class StringReverse: public Solver<string,string>{

public:
    string solve(string p){
        int n = p.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(p[i], p[n - i - 1]);

        return p;
    }

};
#endif //SECONDMIILESTONE_STRINGREVERSE_H
