//
// Created by adi on 1/15/19.
//

#ifndef PART2_RUNTHEPROGRAM_H
#define PART2_RUNTHEPROGRAM_H

#include <string>

#include "Server.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "SearcherSolver.h"
#include "AStar.h"

using namespace std;

class RunTheProgram {
    Server* par;
public:
    void run(string s);

    virtual ~RunTheProgram();
};


#endif //PART2_RUNTHEPROGRAM_H
