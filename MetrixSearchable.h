//
// Created by adi on 1/7/19.
//

#ifndef PART2_METRIXSEARCHABLE_H
#define PART2_METRIXSEARCHABLE_H

#include "Searchable.h"
#include <vector>
class MetrixSearchable: public Searchable<class T> {
    vector<vector<State <T>>> metrix;
    State<T> start;
    State<T> end;

public:
    virtual State <T> getInitalState() {
        return this->start;
    }

    virtual State<T> getGoalState() {
        return  this->end;
    }

   /* virtual vector<State<T>>getAllPossibleStates(State<T> state){
        vector<State<T>> canGo;
        State<int> zero = new State<int>(0);

        for(int i = 1 ; i < this->metrix.size();i++){
            if(state.Equals(this->metrix[i][0])){
                for(int j = 1; j < this->metrix[i].size();j++){
                    if(this->metrix[i][j].Equals(zero) )
                }
            }
        }

    }*/

    virtual unsigned long int numberOfNodes(){
        return this->metrix.size();
    }

    virtual void ChangeTheVisit(bool visit , int i ){
        this->metrix[i][0].setIsVisted(visit);
    }


};


#endif //PART2_METRIXSEARCHABLE_H
