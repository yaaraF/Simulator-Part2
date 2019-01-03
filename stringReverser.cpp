//
// Created by adi on 1/3/19.
//

#include <algorithm>
#include "stringReverser.h"

string stringReverser::solve(string problem) {
    reverse(problem.begin(),problem.end());
    return problem;
}
