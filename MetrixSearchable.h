//
// Created by adi on 1/7/19.
//

#ifndef PART2_METRIXSEARCHABLE_H
#define PART2_METRIXSEARCHABLE_H

#include "Searchable.h"
#include <vector>
template <class T>
class MetrixSearchable: public Searchable<T> {
    vector<vector<State <vector<int>>>> metrix;
    State<T> start;
    State<T> end;

public:
    virtual State <T> getInitalState() {
        return this->start;
    }

    virtual State<T> getGoalState() {
        return  this->end;
    }

    virtual vector<State<T>>getAllPossibleStates(State<T> state){
     
        vector<int> pos = state.getState();
        int i = pos[0];
        int j = pos[1];
        vector<State <vector<int>>> canGo;
     //we will get it in the constractor;
      //we can go up down left and right.
      //we will check the bondris of the metrix  to insert when can i go
      if(i ==0 && j ==0 ){
          State<T> temp = this->metrix[i][j+1];
          canGo.push_back(temp);
          canGo.push_back(this->metrix[i+1][j]);

      }else if (i == 0 && j <this->metrix[i].size()){
          canGo.push_back(this->metrix[i+1][j]);
          canGo.push_back(this->metrix[i][j+1]);
          canGo.push_back(this->metrix[i][j-1]);
      }else if (j == 0 && i < this->metrix.size()) {
          canGo.push_back(this->metrix[i - 1][j]);
          canGo.push_back(this->metrix[i][j + 1]);
          canGo.push_back(this->metrix[i+1][j]);
      }
      else if (j == this->metrix[i].size() && i == this->metrix.size()) {
          canGo.push_back(this->metrix[i - 1][j]);
          canGo.push_back(this->metrix[i][j - 1]);
      }else if (j == this->metrix[i].size() && i < this->metrix.size()) {
          canGo.push_back(this->metrix[i - 1][j]);
          canGo.push_back(this->metrix[i][j - 1]);
          canGo.push_back(this->metrix[i+1][j]);
      }
      else if (j < this->metrix[i].size() && i == this->metrix.size()) {
          canGo.push_back(this->metrix[i - 1][j]);
          canGo.push_back(this->metrix[i][j - 1]);
          canGo.push_back(this->metrix[i][j+1]);
      }else{
          canGo.push_back(this->metrix[i - 1][j]);
          canGo.push_back(this->metrix[i+1][j]);
          canGo.push_back(this->metrix[i][j+1]);
          canGo.push_back(this->metrix[i][j-1]);
      }

        return canGo;

    }


    /*virtual void  InitlizeAllStates(){
        for (int i = 1; i < this->metrix.size(); i++)
            this->metrix[i][0].setIsVisted(false);
    }*/


};


#endif //PART2_METRIXSEARCHABLE_H
