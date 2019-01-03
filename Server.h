//
// Created by yaara on 1/3/19.
//

#ifndef PART2_SERVER_H
#define PART2_SERVER_H

#include "ClientHandler.h"

class Server {
public:
    virtual void open(int port, ClientHandler cl)=0;
    virtual void stop()=0;


};


#endif //PART2_SERVER_H
