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
class comp{
public:
    bool operator()(const State<T>* left , const State<T>* right){
        return left->getPathCost()>right->getPathCost();
    }
};


template<class T>
class MyPriorityQueue{
    priority_queue<State<T>*,vector<State<T>*>,comp<T>> pq;
public:
    unsigned long Count(){
        return this->pq.size();
    }
    State<T>* popFromthePq(){
        State<T>* temp =  this->pq.top();
        this->pq.pop();
        return temp;
    }

    void add(State<T>*s ){
        this->pq.push(s);
    }

    bool contains(State<T>*s){
       bool returnVal = false;
        vector<State <T>*> temp;
        while(!this->pq.empty()){
            State<T>* var = this->popFromthePq();
            temp.push_back(var);
            if(var->Equals(s)){
                returnVal = true;
                break;
            }

        }
        for(int i = 0 ; i <temp.size();i++ ){
            this->add(temp[i]);
        }

        return returnVal;

    }

    void updatePriority(State<T>*current ,State<T>*update){
       double cost;
        vector<State<T>*> temp;
       while (!this->pq.empty()){
            State<T>* top = this->popFromthePq();
            temp.push_back(top);
            if(current->Equals(top)){
                top->setCameFrom(update);
                cost = update->getPathCost()+current->getCost();
                top->setPathCost(cost);
                break;
            }
        }

        for(int i = 0 ; i<temp.size();i++){
            this->pq.push(temp[i]);
        }
    }

    const priority_queue<State<T> *, vector<State<T> *>, comp<T>> &getPq() const {
        return pq;
    }

    void print(){
        while(!this->pq.empty()){
            cout<<this->pq.top()->getPathCost()<<endl;
            this->pq.pop();

        }
    }


};
#endif //PART2_MYPRIORITYQUEUE_H
