//
// Created by adi on 1/11/19.
//

#ifndef PART2_ASTAR_H
#define PART2_ASTAR_H

#endif //PART2_ASTAR_H

#include "Searcher.h"
#include "algorithm"
using namespace std;

template <class T>
class AStar:public Searcher<T>{
    int nodeThatEleveted = 0 ;

    virtual string search(Searchable<T> *searchable);
    virtual int getNumberOfNodeElevatde(){
        return this->nodeThatEleveted;
    }
};

template<class T>
string AStar<T>::search(Searchable<T> *searchable) {
    vector<State<T>*> myTempList;

    State<T>* goal = searchable->getGoalState();
    State<T>* start = searchable->getInitalState();
    vector<State<T>*> open;

    start->setPathCost(start->getCost());



    open.push_back(start);
    while(!open.empty()){
        State<T>* state = open.back();
        open.pop_back();
        double stateCost = state->getCost();
        this->nodeThatEleveted++;

        if(state->Equals(goal)){

            break;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(state);
        while (!adj.empty()){
            State<T>* temp = adj.back();
            adj.pop_back();
            double huristic = abs(temp->getI() - goal->getI()) +abs(temp->getJ() - goal->getJ());
            double newCost = huristic + state->getPathCost() + temp->getPathCost();



            if ( find(myTempList.begin(),myTempList.end(),temp)!=myTempList.end()) {
                double preCost = temp->getCost();
                if (newCost < preCost){
                    temp->setCameFrom(state);
                    temp->setPathCost(newCost);
                }
            } else {
                open.push_back(temp);
                temp->setCameFrom(state);
                myTempList.push_back(temp);
            }
        }
    }

    vector<State<T>*> path = this->ThePath(searchable->getGoalState());

    string solution =  searchable->WhereToGo(path);
    return solution;
}


