//
// Created by yaara on 1/3/19.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H


template <class P, class S>
class Solver{
public:
    virtual S solve(P problem)=0;
};


#endif //PART2_SOLVER_H
