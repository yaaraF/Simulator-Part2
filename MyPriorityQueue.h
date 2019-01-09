//
// Created by adi on 1/8/19.
//

#ifndef PART2_MYPRIORITYQUEUE_H
#define PART2_MYPRIORITYQUEUE_H

#include <queue>
#include <iostream>
#include "State.h"
using namespace std;

template<class T>
class MyPriorityQueue{
    priority_queue<State<T>> pq;
public:
    unsigned long Count(){
        return this->pq.size();
    }
    State<T> popFromthePq(){
        State<T> temp =  this->pq.top();
        this->pq.pop();
        return temp;
    }

    void add(State<T>s ){
        this->pq.push(s);
    }

    bool contains(State<T>s){
       bool returnVal = false;
        vector<State <T>> temp;
        while(!this->pq.empty()){
            State<T> var = this->popFromthePq();
            if(var.Equals(s)){
                returnVal = true;
                break;
            }

        }
        for(int i = 0 ; i <temp.size();i++ ){
            this->add(temp[i]);
        }

        return returnVal;

    }




};
#endif //PART2_MYPRIORITYQUEUE_H
