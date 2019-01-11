//
// Created by adi on 1/8/19.
//

#ifndef PART2_BESTFIRSTSERACHE_H
#define PART2_BESTFIRSTSERACHE_H

#include "SeracherExtend.h"
#include <unordered_set>

using namespace std;
template <class T>
class BestFirstSearch:public SearcherExtend<T>{

public:
    virtual string search(Searchable<T> *searchable) {
        State<T>* first = searchable->getInitalState();
        this->openList->add(first);

        unordered_set<State<T>*> closed;
        typename unordered_set<State<T>*>::iterator itOnClosed;
        State<T>* goal = searchable->getGoalState();

        while (!this->openList->empty()) {

            State<T>* n = this->openList->popFromthePq();
            closed.insert(n);
            if (n == goal) {
                // TODO: end algorithm. return solution
                //return;
            }
            this->evluetedNode+=1;

            typename vector<State<T>*>::iterator iterator1;
            vector<State<T>*> successors = searchable->getAllPossibleStates(n);

            iterator1 = successors.begin();

            for (;iterator1!=successors.end();++iterator1) {
                State<T> *it = (*iterator1);

                double currPath = n->getPathCost() + it->getCost();
                itOnClosed = closed.find(it);

                if (itOnClosed ==closed.end() && !this->openList->contains(it)) {
                    it->setCameFrom(n);
                    it->setPathCost(currPath);
                    this->openList->add(it);
                } else if (currPath < it->getPathCost()) {
                    if (!this->openList->contains(it)) {
                        this->openList->add(it);
                    } else {
                        this->openList->updatePriority(it,n);
                    }
                }
            }


        }

        vector<State<T>*> path = this->ThePath(searchable->getGoalState());

        string solution = searchable->WhereToGo(path);
        return solution;
    }

    virtual int getNumberOfNodeElevatde() {
        return this->evluetedNode;
    }

};
#endif //PART2_BESTFIRSTSERACHE_H
