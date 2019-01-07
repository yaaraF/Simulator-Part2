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
    State(T s){

        this->state = s;
    }

    bool Equals(State<T> s){
        return this->state==s;
    }

    bool isIsVisted() const {
        return isVisted;
    }

    void setIsVisted(bool isVisted) {
        State::isVisted = isVisted;
    }

};


#endif //PART2_STATE_H
