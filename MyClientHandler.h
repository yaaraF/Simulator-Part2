
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

    CacheManager<string,string> *cm;
  Solver<Searchable<vector<int>>*,string>* searcher;
  Searchable <vector<int>> *matrixSrc;
    State<vector<int>> *myState;
    vector<State<vector<int>>*> states;

public:
    MyClientHandler(CacheManager<string, string> *cm, Solver<Searchable<vector<int>> *, string> *searcher);


    void handlerClient(int clientId);
    vector<string> split(string line);
    void createMatrix(vector<vector<string>> lines, vector<vector<State<vector<int>> *>> &matrix);
    void writeTheSolution(int id,const char* problem);

    virtual ~MyClientHandler();
};


#endif //PART2_MYCLIENTHANDLER_H
