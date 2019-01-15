
#include "MyParallelServer.h"
#include <cstring>

void MyParallelServer::open(int port, ClientHandler *cH) {

    int sockfd, portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    this->passingData->clientHandler = cH;
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    struct sockaddr_in cli_addr;
    int clilen, cliSock;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);

    timeval timeout;
    timeval timeoutCli;

    while (true) {
        // Accept actual connection from the client
        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        timeout.tv_usec = 0;
        timeout.tv_sec = 10;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        this->passingData->sockfd = cliSock;
        if (cliSock < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                stop();
                break;

            } else {
                perror("other error");
                stop();
                break;
            }
        }
        pthread_t pthread;
        if (pthread_create(&pthread, nullptr, MyParallelServer::threadManager, passingData) != 0) {
            perror("thread failed");
        }
        timeoutCli.tv_usec = 0;
        timeoutCli.tv_sec = 0;
        setsockopt(cliSock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeoutCli, sizeof(timeoutCli));
        this->threads.push_back(pthread);
    }

}

void *MyParallelServer::threadManager(void *data) {
    struct dataPass *passingData = (struct dataPass *) data;
    passingData->clientHandler->handlerClient(passingData->sockfd);

}

void MyParallelServer::stop() {
    for (unsigned long thread : this->threads) {
        pthread_join(thread, nullptr);
    }
}

MyParallelServer::~MyParallelServer() {
    close(this->sockfd);
    delete (this->passingData);
    this->threads.clear();
}




