//
// Created by yaara on 1/3/19.
//

#ifndef PART2_TEST_H
#define PART2_TEST_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "State.h"
#include "Searcher.h"
#include "MetrixSearchable.h"

class Test :public ClientHandler {
        /* Solver<string,string> *solver;
         CacheManager<string,string> *cm;*/
    //    Searcher<vector<int>> * searcher;
       vector<vector<State<vector<int>>*>> metrix;


        State<vector<int>>start;
        State<vector<int>> exit;
public:

    Test();

    void handlerClient(int clientId);
        vector<string> split(string line);
        void addLineToMetrix(vector<string> line,int counter);
};


#endif //PART2_TEST_H
