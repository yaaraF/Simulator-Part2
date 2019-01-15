//
// Created by adi on 1/15/19.
//

#include "RunTheProgram.h"

void RunTheProgram::run(string s) {

    int port = stoi(s.c_str());
    this->par=new MyParallelServer();
    CacheManager<string,string> *cacheManager=new FileCacheManager<string,string>();
    Searcher<vector<int>>* searcher = new AStar<vector<int>>();
    Solver<Searchable<vector<int>>*,string>* solver = new SercherSolver(searcher);
    ClientHandler *clientHandler=new MyClientHandler(cacheManager,solver);
    this->par->open(port,clientHandler);
    cout<<"enterToContinue"<<endl;
    cin.ignore();
    this->par->stop();

}

RunTheProgram::~RunTheProgram() {
    delete (this->par);
}
