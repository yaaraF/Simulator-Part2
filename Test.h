//
// Created by yaara on 1/3/19.
//

#ifndef PART2_TEST_H
#define PART2_TEST_H

#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "State.h"
#include "Searcher.h"
#include "MetrixSearchable.h"
#include "MyPriorityQueue.h"
#include "AStar.h"

class Test :public ClientHandler {
    CacheManager<string,string> *cm;
//    Searcher<vector<int>> * searcher;
    vector<vector<State<vector<int>>*>> metrix;
    State<vector<int>> start;
    Searchable<vector<int>> *searchable;
    State<vector<int>> exit;
    string matrixStr;
public:
    virtual ~Test();

    Test();

    void handlerClient(int clientId);
        vector<string> split(string line);
        void addLineToMetrix(vector<string> line,int counter);

    void writeTheSolution(int id, const char* problem);
    void checkRQ();
    void testParllel();
    void EmpiryTrail();

};


#endif //PART2_TEST_H
