//
// Created by yaara on 1/8/19.
//
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "MyClientHandler.h"
#include <mutex>

using namespace std;

 void MyClientHandler::handlerClient(int clientId) {
     cout<<"im hereee" <<endl;
     vector<vector<State<vector<int>>*>> matrix;
     State<vector<int>> start;
     State<vector<int>> exit;
    int clilen;
    ssize_t n;
    vector<string> lineMetrix;
    vector<int> state;
    int countLine = 0;
    bool afterEnd = false;
    bool wasStart = false;
    bool wasExit = false;
     cout<<"$ 0"<<endl;
    while (!wasExit) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientId, buffer, 1000);

        if (n < 0) {
            perror("ERROR reading from socket");
            // exit(1);
        }

        if (strcmp(buffer, "end") != 0) {
            if (!afterEnd) {
                matrixStr += buffer;
                matrixStr+="$";
                lineMetrix = split(buffer);
                addLineToMetrix(lineMetrix, countLine,matrix);
                countLine++;
            } else {
                lineMetrix = split(buffer);
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if (!wasStart) {
                    if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                        || state[1] > matrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    matrixStr += buffer;
                    wasStart = true;
                    start.setState(state);
                    state.clear();
                } else {
                    if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                        || state[1] > matrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    matrixStr += buffer;
                    wasExit = true;
                    exit.setState(state);
                    state.clear();
                }
            }
        } else {
            afterEnd = true;
        }

    }
     cout<<"$ 2"<<endl;
    mutex mutex1;
    mutex1.lock();
     cout<<"$ 3"<<endl;
    if (!cm->isProblemExist(matrixStr)) {
        cout<<"$ 4"<<endl;
        string solution = searcher->search(
                new MetrixSearchable<vector<int>>(matrix, start,exit, matrixStr));
        cm->saveSolution(matrixStr, solution);
    } else {
        cout<<"$ 5"<<endl;
       writeTheSolution(clientId, this->matrixStr.c_str());
    }
     mutex1.unlock();
}


vector<string> MyClientHandler::split(string line) {
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

void MyClientHandler::addLineToMetrix(vector<string> line, int iCounter, vector<vector<State<vector<int>>*>> &matrix) {
    int temp;
    vector<int> pos;
    for (int j = 0; j < line.size(); ++j) {
        if (strcmp(line[j].c_str(), "-1") == 0) {
            temp = -1;
        } else {
            temp = stoi(line[j]);
        }
        pos.push_back(iCounter);
        pos.push_back(j);
        State<vector<int>> *myState = new State<vector<int>>(pos, temp, false);
        matrix[iCounter].push_back(myState);
        pos.clear();
    }
}

void MyClientHandler::writeTheSolution(int id, const char* problem) {
    string solution = cm->getSolution(problem);
    ssize_t n = write(id, solution.c_str(), 1024);

    if (n < 0) {
        perror("ERROR writing to socket");
        //exit(1);
    }
}
