//
// Created by yaara on 1/3/19.
//

#ifndef PART2_MYSERIALSERVER_H
#define PART2_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer:public Server {
public:
    virtual void open(int port, ClientHandler cl);
    virtual void stop();

};


#endif //PART2_MYSERIALSERVER_H
