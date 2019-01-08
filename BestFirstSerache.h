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
        this->openList.add(searchable->getInitialState());

        unordered_set<State<T>> closed;
        State<T> goal = searchable->getGoalState();
        while (!this->openList.empty()) {

            State<T> n = this->openList.top();
            this->openList.pop();
            closed.insert(n);
            if (n == goal) {
                // TODO: end algorithm. return solution
                //return;
            }
            typename vector<State<T>>::iterator iterator1;
            vector<State<T>> successors = searchable->getAllPossibleStates(n);

            iterator1 = successors.begin();

            for (;iterator1!=successors.end();++iterator1) {
                double currPath = n.getPathCost() + iterator1->getCost();

                if (closed.find(iterator1) != successors.end() && !this->openList.contains(iterator1)) {
                    iterator1>setCameFrom(n);
                    iterator1->setPathCost(currPath);
                    this->openList.add(iterator1);
                } else if (currPath < iterator1->getPathCost()) {
                    if (!this->openList.contains(iterator1)) {
                        this->openList.add(iterator1);
                    } else {
                        this->openList.updatePriority(iterator1);
                    }
                }
            }
        }
    }

    virtual int getNumberOfNodeElevatde() = 0;

};
#endif //PART2_BESTFIRSTSERACHE_H
