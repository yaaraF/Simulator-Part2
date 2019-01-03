//
// Created by yaara on 1/3/19.
//

#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handlerClient(int clientId) {
    int clilen;
    ssize_t n;
    bool keepReading = true;


    while(keepReading) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientId, buffer, 1000);

        //finish the conversetion.
        if(strcmp(buffer,"end") == 0){
            return;
        }

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if(this->cm->isProblemExist(buffer)){
            string solution = this->cm->getSolution(buffer);
            n = write(clientId, solution.c_str(), 1000);

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }else{
            this->cm->saveSolution(buffer,sou);

        }


    }


}

void MyTestClientHandler::writeTheSolution(int id, char *buffer) {

}
