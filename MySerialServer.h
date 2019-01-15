
#ifndef PART2_MYSERIALSERVER_H
#define PART2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;

class MySerialServer:public Server {
    int sockfd;
public:
    virtual void open(int port, ClientHandler *cl);
    virtual void stop();
    static void listenToClient(int sockfd, ClientHandler *cH);

};


#endif //PART2_MYSERIALSERVER_H
