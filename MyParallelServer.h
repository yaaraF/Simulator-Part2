
#ifndef PART2_PARALLELSERVER_H
#define PART2_PARALLELSERVER_H

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include "Server.h"
#include "MyClientHandler.h"

using namespace server_side;

    class MyParallelServer : public Server {
        struct dataPass *passingData = new dataPass();
        vector<pthread_t> threadList;
        int port;
        int sockfd;
        int serverfd;
        vector <pthread_t> threads;
    public:
        void open(int port, ClientHandler *cH);

        void stop();

        static void* threadManager (void* data);

        virtual ~MyParallelServer();


    };


#endif //PART2_PARALLELSERVER_H
