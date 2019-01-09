//
// Created by adi on 1/8/19.
//

#ifndef PART2_DFS_H
#define PART2_DFS_H
#include<bits/stdc++.h>

#include "Searcher.h"
using namespace std;

template <class T>
class DFS:public Searcher<T> {

public:
    virtual vector<string> search(Searchable<T> *searchable) {
        // Initially mark all verices as not visited
        //vector<bool> visited(V, false);
        State<T> goal = searchable->getGoalState();
        // Create a stack for DFS
        stack<State<T>>stack;
        State<T> current = searchable->getInitalState();
        current.setCameFrom(NULL);

        typename vector<State<T>>::iterator it;

        // Push the current source node.
        stack.push(current);

        while (!stack.empty())
        {
            // Pop a vertex from stack and print it
           current = stack.top();
            stack.pop();

            if(current.Equals(goal)){
                break;
            }

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            if (!current.isIsVisted())
            {

                current.setIsVisted(true);
            }

            vector<State<T>> canGo = searchable->getAllPossibleStates(current);
            it = canGo.begin();
            for(; it!= canGo.end() ;++it){

                State<T> temp = (*it);
                if( !temp.isIsVisted()) {
                    temp.setIsVisted(true);
                    temp.setCameFrom(&current);
                    stack.push_back(temp);
                }
            }

        }

        this->ThePath(current);
    }

    virtual int getNumberOfNodeElevatde();

};


#endif //PART2_DFS_H
