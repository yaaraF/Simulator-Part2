//
// Created by adi on 1/7/19.
//

#ifndef PART2_METRIXSEARCHABLE_H
#define PART2_METRIXSEARCHABLE_H

#include <iostream>
#include "Searchable.h"

template <class T>
class MetrixSearchable: public Searchable<T> {
    vector<vector<State <vector<int>>*>> metrix;
    State<T> start;
    State<T> end;
    string matrixStr;

public:
    virtual State <T>* getInitalState() {
       vector<int> temp = this->start.getState();

        return this->metrix[temp[0]][temp[1]];
    }

    virtual State<T>* getGoalState() {
        vector<int> temp = this->end.getState();

        return this->metrix[temp[0]][temp[1]];
    }
    virtual vector<State<T>*>getAllPossibleStates(State<T>* state){
     
        vector<int> pos = state->getState();
        int i = pos[0];
        int j = pos[1];
      vector<State <vector<int>>*> temp;
       vector<State <vector<int>>*> canGo;
//     //we will get it in the constractor;
//      //we can go up down left and right.
//      //we will check the bondris of the metrix  to insert when can i go
     if(i ==0 && j ==0 ) {

         temp.push_back(this->metrix[i][j + 1]);
          temp.push_back(this->metrix[i + 1][j]);
     }
      else if (i == 0 && j <this->metrix[i].size()-1){
          temp.push_back(this->metrix[i+1][j]);
          temp.push_back(this->metrix[i][j+1]);
          temp.push_back(this->metrix[i][j-1]);
      }else if (i == 0 && j ==this->metrix[i].size()-1){
         temp.push_back(this->metrix[i+1][j]);
         temp.push_back(this->metrix[i][j-1]);
     }

      else if (j == 0 && i < this->metrix.size()-1) {
          temp.push_back(this->metrix[i - 1][j]);
          temp.push_back(this->metrix[i][j + 1]);
          temp.push_back(this->metrix[i+1][j]);
      }
     else if (j == 0 && i == this->metrix.size()-1) {
         temp.push_back(this->metrix[i - 1][j]);
         temp.push_back(this->metrix[i][j + 1]);
     }
      else if (j == this->metrix[i].size()-1 && i == this->metrix.size()-1) {
          temp.push_back(this->metrix[i - 1][j]);
          temp.push_back(this->metrix[i][j - 1]);
      }else if (j == this->metrix[i].size()-1 && i < this->metrix.size()-1) {
          temp.push_back(this->metrix[i - 1][j]);
          temp.push_back(this->metrix[i][j - 1]);
          temp.push_back(this->metrix[i+1][j]);
      }
      else if (j < this->metrix[i].size()-1 && i == this->metrix.size()-1) {
         temp.push_back(this->metrix[i - 1][j]);
         temp.push_back(this->metrix[i][j - 1]);
         temp.push_back(this->metrix[i][j + 1]);

     }else{

         temp.push_back(this->metrix[i+1][j]);
         temp.push_back(this->metrix[i][j+1]);
         temp.push_back(this->metrix[i - 1][j]);
          temp.push_back(this->metrix[i][j-1]);
      }

       if(!temp.empty()){
        for(int i=0; i<temp.size();++i){
            if(temp[i]->getCost()!=-1) {
                canGo.push_back(temp[i]);
            }
            }

        }
        return canGo;
    }

    virtual string WhereToGo(vector<State<T>*> path){
        string ans;
        string went;
        for(int i = 0 ; i < path.size()-1; i ++){
            State<T>* r = path[i];
            State<T> *second = path[i+1];
            vector<int> cor = r->getState();
            vector<int> next = second->getState();
            if(cor[0]>next[0]){
                ans = "up";
            }else if(cor[1] > next[1]){
                ans = "left";
            }else if(cor[1]<next[1]){
                ans = "right";

            }else{
                ans = "down";

            }
            went+=ans;
            ans = ",";
            went+=ans;
        }
        went.pop_back();
        return went;
    }
    /*virtual vector<string> WhereToGo(vector<State<T>*> path){
        string ans;
        vector<string> went;
        for(int i = 0 ; i < path.size()-1; i ++){
            State<T>* r = path[i];
            State<T> *second = path[i+1];
            vector<int> cor = r->getState();
            vector<int> next = second->getState();
            if(cor[0]>next[0]){
                ans = "up";
            }else if(cor[1] > next[1]){
                ans = "left";
            }else if(cor[1]<next[1]){
                ans = "right";

            }else{
                ans = "down";

            }
            went.push_back(ans);
            ans = " ";
            went.push_back(ans);
        }
        went.pop_back();
        return went;
    }*/

    MetrixSearchable(const vector<vector<State<vector<int>> *>> &metrix, const State<T> &start, const State<T> &end,
                     const string &matrixStr) : metrix(metrix), start(start), end(end), matrixStr(matrixStr) {}


};


#endif //PART2_METRIXSEARCHABLE_H
