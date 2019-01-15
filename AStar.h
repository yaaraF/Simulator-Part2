//
// Created by adi on 1/11/19.
//

#ifndef PART2_ASTAR_H
#define PART2_ASTAR_H

#endif //PART2_ASTAR_H

#include "Searcher.h"
#include "algorithm"

using namespace std;

template<class T>
class AStar : public Searcher<T> {
    int nodeThatEleveted = 0;
    vector<State<T> *> open1;
public:
    virtual ~AStar() {
        this->open1.clear();
    }

private:
    virtual int getNumberOfNodeElevatde() {
        return this->nodeThatEleveted;
    }

    string tempMyAStar(Searchable<T> *searchable) {
        int k = 0;
        vector<State<T> *> close;
        State<T> *goal = searchable->getGoalState();
        State<T> *start = searchable->getInitalState();

        double f = abs(start->getI() - goal->getI()) + abs(start->getJ() - goal->getJ());

        this->open1.push_back(start);

        while (!this->open1.empty()) {

            State<T> *current = this->lowestVal(goal);
            current->setIsVisted(true);

            close.push_back(current);


            if (current->Equals(goal)) {
                break;
            }
            this->nodeThatEleveted++;

            vector<State<T> *> adj = searchable->getAllPossibleStates(current);
            while (!adj.empty()) {
                State<T> *temp = adj.back();
                adj.pop_back();

                if (temp->isIsVisted()) {
                    continue;
                }

                double pathFromCurrent = current->getPathCost() + temp->getCost();


                if (find(this->open1.begin(), this->open1.end(), temp) != this->open1.end()) {
                    if (temp->getPathCost() < pathFromCurrent) {
                        continue;
                    }
                } else if (find(close.begin(), close.end(), temp) != close.end()) {
                    if (temp->getPathCost() < pathFromCurrent) {
                        continue;
                    }

                } else {
                    this->open1.push_back(temp);
                }
                temp->setPathCost(pathFromCurrent);
                temp->setCameFrom(current);
            }
        }
        string solution;
        if (goal->getCameFrom() == NULL) {
            solution = "-1";

        } else {
            vector<State<T> *> path = this->ThePath(searchable->getGoalState());
            solution = searchable->WhereToGo(path);
        }
        return solution;
    }


    string search(Searchable<T> *searchable) {
        return this->tempMyAStar(searchable);
    }
    State<T> *lowestVal(State<T> *goal) {
        vector<State<T> *> temp;

        State<T> *lowest = open1.back();
        open1.pop_back();
        double huristic = abs(lowest->getI() - goal->getI()) + abs(lowest->getJ() - goal->getJ());
        double first = huristic + lowest->getPathCost();
        while (!this->open1.empty()) {
            State<T> *state = open1.back();
            open1.pop_back();


            huristic = abs(state->getI() - goal->getI()) + abs(state->getJ() - goal->getJ());
            double newCost = huristic + state->getPathCost();

            if (newCost < first) {
                first = newCost;
                temp.push_back(lowest);
                lowest = state;
                continue;
            }
            temp.push_back(state);


        }

        for (int i = 0; i < temp.size(); i++) {
            this->open1.push_back(temp[i]);
        }

        return lowest;
    }

    void moveToOpen(vector<State<T> *> close, State<T> *temp) {
        vector<State<T> *> move;
        typename vector<State<T> *>::iterator it;
        it = close.begin();
        for (; it != close.end(); ++it) {
            State<T> *now = close.back();
            close.pop_back();
            move.push_back(now);
            if (now->Equals(temp)) {
                this->open1.push_back(now);
                return;
            }
        }
    }

};


