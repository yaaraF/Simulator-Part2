//
// Created by yaara on 1/9/19.
//

#ifndef PART2_PARALLELSERVER_H
#define PART2_PARALLELSERVER_H

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include "ClientHandler.h"

class ParallelServer {
    int port;
    int clientfd;
    int serverfd;
public:
    void open(int port, ClientHandler *cH);

};


#endif //PART2_PARALLELSERVER_H
