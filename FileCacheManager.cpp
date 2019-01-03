//
// Created by yaara on 1/3/19.
//

#include "FileCacheManager.h"

using namespace std;

template<class P, class S>
FileCacheManager<P, S>::FileCacheManager() {
  openF();
}

template<class P, class S>
void FileCacheManager<P, S>::openF() {
    ifstream table;
    table.open("solutionTable.txt");
    if (table.good()) {
//        loadFileTable(table);
//        table.close();
    }
    else{
    }
}

template<class P, class S>
bool FileCacheManager<P, S>::isProblemExist(P problem) {
    return this->solutions.find(problem) != this->solutions.end();
}

template<class P, class S>
S FileCacheManager<P, S>::getSolution(P problem) {
    return this->solutions.at(problem);
}

template<class P, class S>
void FileCacheManager<P, S>::saveSolution(S solution, P problem) {
    ofstream table(FILE_NAME, ios::app);
    // TODO each problem and solution need toString!!
    table << problem << "$";
    table << solution << endl;
    table.close();
    // save the new solution to the solutions
    this->solutions.insert(problem, solution);


}

template<class P, class S>
void FileCacheManager<P, S>::loadFileTable(ifstream file) {
  /*  string line;
    while (getline(file, line)) {
        size_t pos = line.find("$");
        string problem = line.substr(0, pos);
        string solution = line.substr(pos + 1, line.length() - 1);
        this->solutions.insert(problem, solution);
    }*/

}


template class FileCacheManager<string,string>;







