
#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H


template <class P, class S>
class Solver{
public:
    virtual ~Solver()= default;

    virtual S solve(P problem)=0;
};


#endif //PART2_SOLVER_H
