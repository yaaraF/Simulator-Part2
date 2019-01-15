//
// Created by yaara on 1/3/19.
//

#ifndef PART2_SERVER_H
#define PART2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    protected:
        struct dataPass {
            int sockfd;
            ClientHandler *clientHandler;
        };
    public:
        virtual void open(int port, ClientHandler *cl) = 0;

        virtual void stop() = 0;
    };
}


#endif //PART2_SERVER_H
