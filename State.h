//
// Created by adi on 1/6/19.
//

#ifndef PART2_STATE_H
#define PART2_STATE_H

template <class T>
class State {

    T state;
    double cost;
    State<T> cameFrom;
    bool isVisted;
public:
    State(T state, double cost, bool isVisted) : state(state), cost(cost), isVisted(isVisted) {}

    double getCost() const {
        return cost;
    }

    bool Equals(State<T> s){
        return this->state==s;
    }

    bool isIsVisted() const {
        return isVisted;
    }

    const State<T> &getCameFrom() const {
        return cameFrom;
    }

    void setCameFrom(const State<T> &cameFrom) {
        State::cameFrom = cameFrom;
    }

    void setIsVisted(bool isVisted) {
        State::isVisted = isVisted;
    }

    T getState() const {
        return state;
    }

    void setState(T state) {
        State::state = state;
    }

};


#endif //PART2_STATE_H
