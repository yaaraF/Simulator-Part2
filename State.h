//
// Created by adi on 1/6/19.
//

#ifndef PART2_STATE_H
#define PART2_STATE_H


#include <clocale>
#include <vector>
using namespace std;

template <class T>
class State {

    T state;
    double cost;
    State <T> *cameFrom;
    bool isVisted;
    double PathCost;
public:

//    State(T state, double cost, const State<T> &cameFrom, bool isVisted) : state(state), cost(cost), cameFrom(cameFrom),
//                                                                           isVisted(isVisted) {}

        State(T state, double cost, bool isVisted) : state(state), cost(cost),
                                                                           isVisted(isVisted)

                                                                           {this->PathCost = cost;
                                                                           this->cameFrom = NULL;}

    State(){
    this->cameFrom = NULL;
}




    double getCost() const {
        return cost;
    }

    bool Equals(State<T>* s){
        return this->state==s->getState();
    }

    bool isIsVisted() const {
        return isVisted;
    }

    const State<T> &getCameFrom() const {
        return cameFrom;
    }

    void setCameFrom(State<T> *cameFrom) {
        State::cameFrom = cameFrom;
    }

    void setIsVisted(bool isVisted) {
        State::isVisted = isVisted;
    }

    T getState() const {
        return state;
    }
     bool operator < (const State<T>* &b) const{
        return this->PathCost < b->PathCost;
    }
    bool operator >(const State<T>* &b) const{
        return this->PathCost > b->PathCost;
    }
    bool operator == (const State<T>* &b) const{
        return this->PathCost == b->PathCost;
    }


    double getPathCost() const {
        return PathCost;
    }

    void setPathCost(double PathCost) {
        State::PathCost = PathCost;
    }

    void setState(T state) {
        State::state = state;
    }

    /*bool operator == (const State<vector<int>>* &b) const{
        vector<int > a = this->getState();
        vector<int> c = b->getState();
        return a[0]== c[0]&& a[1] == c[1];
    }*/


};


#endif //PART2_STATE_H
