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
    virtual string search(Searchable<T> *searchable);
    virtual int getNumberOfNodeElevatde();

};

template<class T>
string BFS<T>::search(Searchable<T> *searchable) {
// Mark all the vertices as not visited



    for (int i = 1; i < searchable->numberOfNodes(); i++)
        searchable->ChangeTheVisit(false,i);

    // Create a queue for BFS
    list<State<T>> queue;

    State<T> current = searchable->getInitalState();
    current.setIsVisted(true);
    queue.push_back(current);

// 'i' will be used to get all adjacent
// vertices of a vertex


    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        current = queue.front();
        //cout << current << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it




       vector<State<T>> canGo = searchable->getAllPossibleStates(current);


       for(int i = 0 ; i < canGo.size() ;i ++){

       }



        /*for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }*/
    }
}


#endif //PART2_BFS_H
