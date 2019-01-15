

#include "RunTheProgram.h"

void RunTheProgram::run(string s) {

    int port = stoi(s.c_str());
    this->par=new MyParallelServer();
    this-> cacheManager=new FileCacheManager<string,string>();
    this-> searcher = new AStar<vector<int>>();
    this-> solver = new SercherSolver(searcher);
    this->clientHandler=new MyClientHandler(cacheManager,solver);
    this->par->open(port,clientHandler);

}

RunTheProgram::~RunTheProgram() {
    delete(this->cacheManager);
    delete(this->searcher);
    delete(this->solver);
    delete(this->clientHandler);
    delete (this->par);
}
