//
// Created by adi on 1/7/19.
//

#ifndef PART2_BFS_H
#define PART2_BFS_H

#include "Searcher.h"
#include <list>
using namespace std;

template <class T>
class BFS:public Searcher<T> {

public:
    virtual string search(Searchable<T> *searchable);
    virtual int getNumberOfNodeElevatde();


};

template<class T>
string BFS<T>::search(Searchable< T> *searchable) {
// Mark all the vertices as not visited

   // searchable->InitlizeAllStates();

    list<State<T>> queue;
    typename vector<State<T>>::iterator it;

    State<T> current = searchable->getInitalState();
    State<T> endNode = searchable->getGoalState();
    current.setIsVisted(true);
    queue.push_back(current);
    current.setCameFrom(NULL);

// 'i' will be used to get all adjacent
// vertices of a vertex


    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        current = queue.front();
        //if we found a path
        if(current.Equals(endNode)){
            break;
        }
        //cout << current << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        vector<State<T>> canGo = searchable->getAllPossibleStates(current);
       it = canGo.begin();
        for(; it!= canGo.end() ;++it){

            State<T> temp = (*it);
            if( !temp.isIsVisted()) {
                temp.setIsVisted(true);
                temp.setCameFrom(&current);
                queue.push_back(temp);
            }
        }

    }

    vector<State<T>> path = this->ThePath(searchable->getGoalState());
}


#endif //PART2_BFS_H
