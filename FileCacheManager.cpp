//
// Created by yaara on 1/3/19.
//

#include "FileCacheManager.h"

template<class P, class S>
bool FileCacheManager<P, S>::isProblemExist(P problem) {
    return false;
}

template<class P, class S>
S FileCacheManager<P, S>::getSolution(P problem) {
    return nullptr;
}

template<class P, class S>
void FileCacheManager<P, S>::saveSolution(S solution, P problem) {

}
