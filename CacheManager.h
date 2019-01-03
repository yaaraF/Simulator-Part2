//
// Created by yaara on 1/3/19.
//

#ifndef PART2_CACHEMANAGER_H
#define PART2_CACHEMANAGER_H

#define FILE_NAME "solutionTable.txt"

#include <fstream>
#include<unordered_map>

using namespace std;

template <class P, class S>
class CacheManager{
protected:
    unordered_map<P,S> solutions;

public:
    virtual bool isProblemExist(P problem)=0;
    virtual S getSolution(P problem)=0;
    virtual void saveSolution(S solution, P problem)=0;
};

#endif //PART2_CACHEMANAGER_H
