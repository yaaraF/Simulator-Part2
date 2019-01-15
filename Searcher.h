

#ifndef PART2_SEARCHER_H
#define PART2_SEARCHER_H

#include "Searchable.h"
#include <string>
#include <algorithm>
using namespace std;

template <class T>
class Searcher{


public:
    virtual ~Searcher()= default;

    virtual string search(Searchable<T> *searchable) = 0;
   virtual int getNumberOfNodeElevatde() = 0;


   vector<State<T>*>ThePath(State<T>* goal){
       vector<State<T>*> path;
       path.push_back(goal);

       while(goal->getCameFrom()!= NULL){
         State<T> *father = goal->getCameFrom();

         path.push_back(father);
          goal = father;
       }

       reverse(path.begin(),path.end());
       return path;


   }

};

#endif //PART2_SEARCHER_H
