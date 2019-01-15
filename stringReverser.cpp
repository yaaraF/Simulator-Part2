
#include <algorithm>
#include "stringReverser.h"

string stringReverser::solve(string problem) {
    reverse(problem.begin(),problem.end());
    return problem;
}
