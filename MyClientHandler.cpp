//
// Created by yaara on 1/8/19.
//
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "MyClientHandler.h"
using namespace std;

void MyClientHandler::handlerClient(int clientId) {
    int clilen;
    ssize_t n;
    vector<string> lineMetrix;
    vector<int> state;
    int countLine=0;
    bool afterEnd=false;
    bool wasStart=false;
    bool wasExit=false;

    while(!wasExit) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientId, buffer, 1000);
        if(strcmp(buffer,"end") != 0 ){
            if(!afterEnd) {
                lineMetrix = split(buffer);
                addLineToMetrix(lineMetrix, countLine);
                countLine++;
            }else{
                lineMetrix = split(buffer);
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if(!wasStart) {
                    wasStart=true;
                    this->start.setState(state);
                    state.clear();
                }
                if(!wasExit){
                    wasExit=true;
                    this->exit.setState(state);
                    state.clear();
                }
            }
        }
        if(strcmp(buffer,"end") == 0){
            afterEnd=true;
        }
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }

    this->searcher->search(new MetrixSearchable <vector<int>>(this->metrix,this->start,this->exit));

}

vector<string> MyClientHandler::split(string line){
    size_t pos = 0;
    int i = 0;
    vector<string> details;
    while ((pos = line.find(",")) != std::string::npos) {
        details.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
        i++;
    }
    details.push_back(line.substr(0, pos));
    return details;
}

void MyClientHandler::addLineToMetrix(vector<string> line, int iCounter) {
    int temp;
    vector<int> pos;
    for(int j=0;j<line.size();++j){
        if(strcmp(line[j].c_str(),"-1") == 0){
          temp=-1;
        }else {
            temp = stoi(line[j]);
        }
        pos.push_back(iCounter);
        pos.push_back(j);
        State<vector<int>> *myState=new State<vector<int>>(pos,temp,false);
        this->metrix[iCounter].push_back(myState);
        pos.clear();
    }
}
