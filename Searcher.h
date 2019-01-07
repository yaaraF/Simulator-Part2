//
// Created by adi on 1/6/19.
//

#ifndef PART2_SEARCHER_H
#define PART2_SEARCHER_H

#include "Searchable.h"
#include <string>
using namespace std;

template <class T>
class Searcher{
   virtual string search(Searchable<T> *searchable) = 0;
   virtual int getNumberOfNodeElevatde() = 0;

};

#endif //PART2_SEARCHER_H
