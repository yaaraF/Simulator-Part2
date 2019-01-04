//
// Created by yaara on 1/3/19.
//

#ifndef PART2_FILECACHEMANAGER_H
#define PART2_FILECACHEMANAGER_H

#include <vector>
#include "CacheManager.h"

template <class P, class S>
class FileCacheManager:public CacheManager<P,S> {
public:
    FileCacheManager();
    virtual bool isProblemExist(P problem);
    virtual S getSolution(P problem);
    virtual void saveSolution(P problem, S solution);
    virtual void loadFileTable();
    virtual void openF();
};




#endif //PART2_FILECACHEMANAGER_H


