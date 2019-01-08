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
public:
    virtual string search(Searchable<T> *searchable) = 0;
   virtual int getNumberOfNodeElevatde() = 0;

   vector<State<T>>ThePath(State<T> goal){
       vector<State<T>> path;
       path.insert(goal);

       while(goal.getCameFrom()!= NULL){
         State<T> father = goal.getCameFrom();
          path.insert(father);
          goal = father;
       }
       path.insert(goal);

   }

};

#endif //PART2_SEARCHER_H
