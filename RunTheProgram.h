
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
    CacheManager<string,string> *cacheManager;
    Searcher<vector<int>>* searcher;
    Solver<Searchable<vector<int>>*,string>* solver;
    ClientHandler *clientHandler;
public:
    void run(string s);

    virtual ~RunTheProgram();
};


#endif //PART2_RUNTHEPROGRAM_H
