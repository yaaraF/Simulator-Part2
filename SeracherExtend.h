//
// Created by adi on 1/8/19.
//

#ifndef PART2_SERACHEREXTEND_H
#define PART2_SERACHEREXTEND_H

#include "Searcher.h"
#include "MyPriorityQueue.h"
#include "State.h"
template <class T>
class SearcherExtend:public Searcher<T>{
    MyPriorityQueue<State<T>>* openList;
    int evluetedNode;
public:

    SearcherExtend() {
        this->openList = new MyPriorityQueue<T>();
        this->evluetedNode = 0 ;

    }

    virtual string search(Searchable<T> *searchable) = 0;
    virtual int getNumberOfNodeElevatde() = 0;

};
#endif //PART2_SERACHEREXTEND_H
