//
// Created by adi on 1/3/19.
//

#ifndef PART2_STRINGREVERSER_H
#define PART2_STRINGREVERSER_H

#include "Solver.h"

#include <string>

using namespace std;

//template <class s, class b>
class stringReverser: public Solver<string,string> {

public:
    virtual string solve(string problem);
};



#endif //PART2_STRINGREVERSER_H
