
#ifndef PART2_BFS_H
#define PART2_BFS_H

#include "Searcher.h"
#include <list>
#include <iostream>

using namespace std;

template <class T>
class BFS:public Searcher<T> {
    int nodeThetElevated = 0;
public:


    virtual int getNumberOfNodeElevatde() {
        return this->nodeThetElevated;
    }


    virtual string search(Searchable<T> *searchable)
    {

        list<State<T> *> queue;
        typename vector<State<T> *>::iterator it;

        State<T> *current = searchable->getInitalState();
        State<T> *endNode = searchable->getGoalState();
        current->setIsVisted(true);

        queue.push_back(current);
        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            current = queue.front();
            queue.pop_front();
            //if we found a path

            if (current->Equals(endNode)) {
                break;
            }
            this->nodeThetElevated++;


            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it

            vector<State<T> *> canGo = searchable->getAllPossibleStates(current);
            it = canGo.begin();
            for (; it != canGo.end(); ++it) {

                State<T> *temp = (*it);
                if (!temp->isIsVisted()) {
                    temp->setIsVisted(true);
                    temp->setCameFrom(current);
                    queue.push_back(temp);
                }
            }

        }
        vector<State<T> *> path = this->ThePath(searchable->getGoalState());

        string solution = searchable->WhereToGo(path);
        return solution;

    }
};


#endif //PART2_BFS_H
