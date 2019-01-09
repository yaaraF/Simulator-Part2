//
// Created by adi on 1/7/19.
//

#ifndef PART2_METRIXSEARCHABLE_H
#define PART2_METRIXSEARCHABLE_H

#include "Searchable.h"

template <class T>
class MetrixSearchable: public Searchable<T> {
    vector<vector<State <vector<int>>>*> metrix;
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
      vector<State <vector<int>>> temp;
       vector<State <vector<int>>> canGo;
//     //we will get it in the constractor;
//      //we can go up down left and right.
//      //we will check the bondris of the metrix  to insert when can i go
      if(i ==0 && j ==0 ) {
          State <vector<int>> s=this->metrix[i][j + 1];
          temp.push_back(s);
         // temp.push_back(this->metrix[i + 1][j]);
      }
//
//      }else if (i == 0 && j <this->metrix[i].size()){
//          temp.push_back(this->metrix[i+1][j]);
//          temp.push_back(this->metrix[i][j+1]);
//          temp.push_back(this->metrix[i][j-1]);
//      }else if (j == 0 && i < this->metrix.size()) {
//          temp.push_back(this->metrix[i - 1][j]);
//          temp.push_back(this->metrix[i][j + 1]);
//          temp.push_back(this->metrix[i+1][j]);
//      }
//      else if (j == this->metrix[i].size() && i == this->metrix.size()) {
//          temp.push_back(this->metrix[i - 1][j]);
//          temp.push_back(this->metrix[i][j - 1]);
//      }else if (j == this->metrix[i].size() && i < this->metrix.size()) {
//          temp.push_back(this->metrix[i - 1][j]);
//          temp.push_back(this->metrix[i][j - 1]);
//          temp.push_back(this->metrix[i+1][j]);
//      }
//      else if (j < this->metrix[i].size() && i == this->metrix.size()) {
//          temp.push_back(this->metrix[i - 1][j]);
//          temp.push_back(this->metrix[i][j - 1]);
//          temp.push_back(this->metrix[i][j+1]);
//      }else{
//          temp.push_back(this->metrix[i - 1][j]);
//          temp.push_back(this->metrix[i+1][j]);
//          temp.push_back(this->metrix[i][j+1]);
//          temp.push_back(this->metrix[i][j-1]);
//      }
//        for(int i=0; i<temp.size();++i){
//            if(temp[i].getCost()!=-1){
//             canGo.push_back(temp[i]);
//            }
//        }
//        return canGo;
    }
    MetrixSearchable(const vector<vector<State<vector<int>>> *> &metrix, const State<T> &start, const State<T> &end)
            : metrix(metrix), start(start), end(end) {}



    /*virtual void  InitlizeAllStates(){
        for (int i = 1; i < this->metrix.size(); i++)
            this->metrix[i][0].setIsVisted(false);
    }*/


};


#endif //PART2_METRIXSEARCHABLE_H
