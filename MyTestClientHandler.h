//
// Created by yaara on 1/3/19.
//

#ifndef PART2_MYTESTCLIENTHANDLER_H
#define PART2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"


class MyTestClientHandler : public ClientHandler {
    Solver<string,string> *solver;
    CacheManager<string,string> *cm;
public:
    void handlerClient(int clientId);

};


#endif //PART2_MYTESTCLIENTHANDLER_H
