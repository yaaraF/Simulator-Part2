
#ifndef PART2_CLIENTHANDLER_H
#define PART2_CLIENTHANDLER_H

#include <iostream>
using namespace std;

class ClientHandler{
public:
    virtual ~ClientHandler() = default;

    virtual void handlerClient(int clientId)=0;
};

#endif //PART2_CLIENTHANDLER_H
