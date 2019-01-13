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
    vector<State<T>*> open1;
    virtual int getNumberOfNodeElevatde(){
        return this->nodeThatEleveted;
    }

    string tempMyAStar(Searchable<T> *searchable){

        vector<State<T>*> close;
        State<T>* goal = searchable->getGoalState();
        State<T>* start = searchable->getInitalState();

        double f = abs(start->getI() - goal->getI()) +abs(start->getJ() - goal->getJ());
        start->setPathCost(start->getCost());
        this->open1.push_back(start);

        while(!this->open1.empty()){
            State<T>* current = this->lowestVal(goal);

            close.push_back(current);
            this->nodeThatEleveted++;
            if(current->Equals(goal)){
                break;
            }

            vector<State<T>*> adj = searchable->getAllPossibleStates(current);
            while (!adj.empty()){
                State<T>* temp = adj.back();
                adj.pop_back();

                double pathFromCurrent = current->getPathCost()+temp->getCost();


               if( find(this->open1.begin(),this->open1.end(),temp)!=this->open1.end()){
                    if(temp->getPathCost()<pathFromCurrent){
                        continue;
                    }
               }else if(find(close.begin(),close.end(),temp)!=close.end()){
                   if(temp->getPathCost()<pathFromCurrent) {
                       continue;
                   }
               }else{
                   this->open1.push_back(temp);
               }

               temp->setPathCost(pathFromCurrent);
               temp->setCameFrom(current);



            }


        }

        vector<State<T>*> path = this->ThePath(searchable->getGoalState());

        string solution =  searchable->WhereToGo(path);
        return solution;




    }








string search(Searchable<T> *searchable) {
  return this->tempMyAStar(searchable);

   /* vector<State<T>*> myTempList;

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
            open.push_back(state);
            break;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(state);
        while (!adj.empty()){
            State<T>* temp = adj.back();
            adj.pop_back();
            double huristic = abs(temp->getI() - goal->getI()) +abs(temp->getJ() - goal->getJ());
            double newCost = huristic + state->getPathCost() + temp->getPathCost();


            if (find(myTempList.begin(),myTempList.end(),temp)!=myTempList.end()) {
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
    return solution;*/
}




State<T>* lowestVal(State<T>* goal) {
    vector<State<T>*> temp;

    State<T>* lowest = open1.back();
    open1.pop_back();


    double huristic = abs(lowest->getI() - goal->getI()) +abs(lowest->getJ() - goal->getJ());
    double first = huristic + lowest->getPathCost();

    while(!this->open1.empty()){
        State<T>* state = open1.back();
        open1.pop_back();


        huristic = abs(state->getI() - goal->getI()) +abs(state->getJ() - goal->getJ());
        double newCost = huristic + state->getPathCost();

        if(newCost<first){
            temp.push_back(lowest);
            lowest = state;
            continue;
        }
        temp.push_back(state);




    }

    for(int i = 0 ; i < temp.size();i++){
        this->open1.push_back(temp[i]);
    }

    return lowest;
}

};


