//
// Created by yaara on 1/8/19.
//

#ifndef PART2_MYCLIENTHANDLER_H
#define PART2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "State.h"
#include "Searcher.h"
#include "MetrixSearchable.h"
#include "BFS.h"

class MyClientHandler: public ClientHandler {
public:
    //Solver<string,string> *solver;
    CacheManager<string,string> *cm;
   Searcher<vector<int>> * searcher;
   /* vector<vector<State<vector<int>>*>> matrix;
    State<vector<int>> start;
    State<vector<int>> exit;*/

public:
    void handlerClient(int clientId);
    vector<string> split(string line);
    void addLineToMetrix(vector<string> line,int counter,vector<vector<State<vector<int>>*>> &matrix);
    void writeTheSolution(int id,const char* problem);
};


#endif //PART2_MYCLIENTHANDLER_H
