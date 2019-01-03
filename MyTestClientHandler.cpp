//
// Created by yaara on 1/3/19.
//

#include <unistd.h>
#include <strings.h>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handlerClient(int clientId) {
    int clilen, cliSock, n;
    char buffer[256];
    // If connection is established then start communicating
    bzero(buffer, 256);
    n = read(cliSock, buffer, 255);
    cout << "now reading" << endl;
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n", buffer);

    // Write a response to the client
    n = write(cliSock, "I got your message", 18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

}
