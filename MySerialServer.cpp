//
// Created by or on 1/3/19.
//

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "MySerialServer.h"
#include <thread>

using namespace std;

void MySerialServer::open(int port, ClientHandler *cH) {
    int sockfd ,portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    this->sockfd = sockfd;

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

    //listenToClient(this->sockfd,cH);
    thread thread1(listenToClient, this->sockfd,cH);

}

void MySerialServer::stop() {

}

void MySerialServer::listenToClient(int sockfd, ClientHandler *cH) {
    struct sockaddr_in cli_addr;
    int clilen, cliSock;

    while (true) {
        listen(sockfd, 1);
        clilen = sizeof(cli_addr);

        // Accept actual connection from the client
        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr,
                         (socklen_t *) &clilen);

        if (cliSock < 0) {
            perror("ERROR on accept");
            exit(1);
        }

    }
}