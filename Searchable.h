//
// Created by adi on 1/6/19.
//

#ifndef PART2_SEARCHABLE_H
#define PART2_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <string>

using namespace std;

template <class T>
class Searchable{
public:
     virtual State <T>* getInitalState() = 0;

    virtual State<T>* getGoalState() = 0;

    virtual vector<State<T>*>getAllPossibleStates(State<T>* s) = 0;

    virtual string WhereToGo(vector<State<T>*> path) = 0 ;

};

#endif //PART2_SEARCHABLE_H
