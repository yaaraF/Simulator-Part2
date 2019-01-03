//
// Created by yaara on 1/3/19.
//

#ifndef PART2_CACHEMANAGER_H
#define PART2_CACHEMANAGER_H

#include<unordered_map>

using namespace std;

template <class P, class S>
class CacheManager{
    unordered_map<P,S> solutions;

public:
    virtual bool isProblemExist(P problem)=0;
    virtual S getSolution(P problem)=0;
    virtual void saveSolution(S solution, P problem)=0;
};

#endif //PART2_CACHEMANAGER_H
