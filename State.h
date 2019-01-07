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
public:
    State(T s){

        this->state = s;
    }

    bool Equals(State<T> s){
        return this->state==s;
    }

};


#endif //PART2_STATE_H
