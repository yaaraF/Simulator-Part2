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
    loadFileTable();
   /* fstream table;
    table.open(FILE_NAME, fstream::in | fstream::out | fstream::app);
    if (!table) {
        throw "Failed in opening file";
    }
    if (table.good()) {
        loadFileTable(table);
       table.close();
    }*/
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
void FileCacheManager<P, S>::saveSolution(P problem, S solution) {
    ofstream table(FILE_NAME, ios::app);
    // TODO each problem and solution need toString!!
    table << problem << "$$$";
    table << solution << endl;
    table.close();
    // save the new solution to the solutions
   this->solutions.insert(pair <P,S>(problem, solution));


}

template<class P, class S>
void FileCacheManager<P, S>::loadFileTable() {
    fstream table;
    table.open(FILE_NAME, fstream::in | fstream::out | fstream::app);
    if (table.fail()) {
        throw "Failed in opening file";
    }
    if(!table.eof()) {
        string line;
        while (getline(table, line)) {
            size_t pos = line.find("$$$");
            string problem = line.substr(0, pos);
            string solution = line.substr(pos + 3, line.length() - 1);
            this->solutions.insert(pair<P,S>(problem,solution));
        }
    }

}


template class FileCacheManager<string,string>;







