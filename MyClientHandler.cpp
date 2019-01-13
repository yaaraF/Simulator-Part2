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
     string matrixStr;
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
        cout<<"ppp "<<buffer<<endl;

        if (n < 0) {
            perror("ERROR reading from socket");
            // exit(1);
        }
        cout<<"$ 1"<<endl;

        if (strcmp(buffer, "end") != 0) {
            cout<<"$ 2"<<endl;
            if (!afterEnd) {
                cout<<"$ 3"<<endl;
                matrixStr += buffer;
                matrixStr+="$";
                lineMetrix = split(buffer);
                addLineToMetrix(lineMetrix, countLine,matrix);
                countLine++;
            } else {
                cout<<"$ 4"<<endl;
                lineMetrix = split(buffer);
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if (!wasStart) {
                    cout<<"$ 5"<<endl;
                    if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                        || state[1] > matrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    matrixStr += buffer;
                    wasStart = true;
                    start.setState(state);
                    state.clear();
                    cout<<"$ 6"<<endl;
                } else {
                    if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                        || state[1] > matrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    cout<<"$ 7"<<endl;
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
    cout<<matrixStr<<endl;
     cout<<"$ 8"<<endl;
    mutex mutex1;
    mutex1.lock();
     cout<<"$ 9"<<endl;
    if (!cm->isProblemExist(matrixStr)) {
        cout<<"$ 10"<<endl;
        string solution = searcher->search(
                new MetrixSearchable<vector<int>>(matrix, start,exit, matrixStr));
        cm->saveSolution(matrixStr, solution);
    } else {
        cout<<"$ 11"<<endl;
       writeTheSolution(clientId, matrixStr.c_str());
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
    cout<<"in add line"<<endl;
    int temp;
    vector<int> pos;
    vector<State<vector<int>>*> vecLine;
    for (int j = 0; j < line.size(); ++j) {
        cout<<"in add line "<<j<<endl;
        if (strcmp(line[j].c_str(), "-1") == 0) {
            cout<<"in -1"<<endl;
            temp = -1;
        } else {
            cout<<"in add line: "<<line[j]<<endl;
            temp = stoi(line[j]);
        }
        cout<<"in add line after if else"<<endl;
        pos.push_back(iCounter);
        pos.push_back(j);
        cout<<"in add line i did push"<<endl;
        State<vector<int>> *myState = new State<vector<int>>(pos, temp, false);
        cout<<"in add line state vector"<<endl;
        vecLine.push_back(myState);
        cout<<"in add line before clear"<<endl;
        pos.clear();
        cout<<"in add line after"<<endl;
    }
    matrix.push_back(vecLine);
}

void MyClientHandler::writeTheSolution(int id, const char* problem) {
    string solution = cm->getSolution(problem);
    ssize_t n = write(id, solution.c_str(), 1024);

    if (n < 0) {
        perror("ERROR writing to socket");
        //exit(1);
    }
}
