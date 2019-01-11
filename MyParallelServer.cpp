//
// Created by yaara on 1/9/19.
//

#include "MyParallelServer.h"
#include <cstring>

void MyParallelServer::open(int port, ClientHandler *cH) {
    int sockfd ,portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    this->serverfd = sockfd;

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

    //listenToClient(this->serverfd,cH);
    thread thread1(threadManager, this->serverfd,cH);

}

void MyParallelServer::stop() {

}

void MyParallelServer::threadManager(int sockfd, ClientHandler *cH) {
    struct sockaddr_in cli_addr;
    int clilen, cliSock;

/*    while (!(params->shouldStop)){
        clientSocketVal = ::accept(params->sockServer, (struct sockaddr *) &client_sock, (socklen_t *) &clilen);
        params->sockClient = clientSocketVal;
        if (params->sockClient < 0) {
            throw invalid_argument("connection with client failed");
        }
        int valread = read( clientSocketVal , buffer, 1024);
        printf("%s\n",buffer );
        send(clientSocketVal , hello , strlen(hello) , 0 );
        printf("Hello message sent\n");
        //args->getClient()->handleClient(&socketRead,&socketWriter);
        pthread_t threadId;
        pthread_create(&threadId, nullptr, &handleClient, params);
    }

    while (true) {
        listen(sockfd, 1);
        clilen = sizeof(cli_addr);
        timeval timeout;
        timeout.tv_sec = 20;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        // Accept actual connection from the client
        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr,
                         (socklen_t *) &clilen);
        if (cliSock < 0)	{
            if (errno == EWOULDBLOCK)	{
                cout << "timeout!" << endl;
                exit(2);
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        //TODO THREAD-problem with static.
      //  thread thread1(MyClientHandler::handlerClient, sockfd);
    }*/
}