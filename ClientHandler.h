//
// Created by yaara on 1/3/19.
//

#ifndef PART2_CLIENTHANDLER_H
#define PART2_CLIENTHANDLER_H

#include <iostream>
using namespace std;
class ClientHandler{
public:
    virtual void handlerClient(iostream input, ostream output)=0;
};

#endif //PART2_CLIENTHANDLER_H
