
#ifndef PART2_CHECKTEMPLETE_H
#define PART2_CHECKTEMPLETE_H

template <class T>
class CheckTemplete {
    T check;

public:
    CheckTemplete(T check) : check(check) {}

    T getCheck() const {
        return check;
    }
};


#endif //PART2_CHECKTEMPLETE_H
