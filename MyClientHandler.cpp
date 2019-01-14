//
// Created by yaara on 1/8/19.
//
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "MyClientHandler.h"
#include <mutex>
#include "FileCacheManager.h"

using namespace std;

void MyClientHandler::handlerClient(int clientId) {
    this->cm=new FileCacheManager<string,string>();
    this->searcher=new BFS<vector<int>>();
    ssize_t n;
    string matrixStr;
    cout<<"im hereee" <<endl;
    vector<vector<State<vector<int>>*>> matrix;
    State<vector<int>> start;
    State<vector<int>> exit;
    vector<string> lineMetrix;
    vector<vector<string>> tempMatrix;
    vector<int> state;
    bool wasEnd = false;
    cout<<"$ 0"<<endl;

    while (!wasEnd) {
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
            matrixStr += buffer;
            matrixStr+="$";
            lineMetrix = split(buffer);
            tempMatrix.push_back(lineMetrix);
            lineMetrix.clear();
        }else{
            wasEnd=true;
            createMatrix(tempMatrix,matrix);
            for(int i=tempMatrix.size()-2;i<tempMatrix.size();++i){
                lineMetrix = tempMatrix[i];
                cout<<"maybe problem i "<<lineMetrix[0]<<endl;
                cout<<"maybe problem j "<<lineMetrix[1]<<endl;
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                    || state[1] > matrix[state[0]].size()) {
                    throw "not valid state";
                }
                if(i==tempMatrix.size()-2){
                    start.setState(state);
                }else{
                    exit.setState(state);
                }
                state.clear();
            }
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
        cout<<"my solution: "<<solution<<endl;
    }
    writeTheSolution(clientId, matrixStr.c_str());
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



void MyClientHandler::writeTheSolution(int id, const char* problem) {
    string solution = cm->getSolution(problem);
    ssize_t n = write(id, solution.c_str(), solution.size());

    if (n < 0) {
        perror("ERROR writing to socket");
        //exit(1);
    }
}

void MyClientHandler::createMatrix(vector<vector<string>> lines, vector<vector<State<vector<int>> *>> &matrix) {
    cout<<"in add line"<<endl;
    int temp;
    vector<int> pos;
    vector<State<vector<int>>*> vecLine;
    for(int i=0;i<lines.size()-2;++i){
        for(int j=0;j<lines[i].size();++j){

            if (strcmp(lines[i][j].c_str(), "-1") == 0) {
                cout<<"in -1"<<endl;
                temp = -1;
            } else {
                cout<<"in add line: "<<lines[i][j]<<endl;
                temp = stoi(lines[i][j]);
            }
            cout<<"in add line after if else"<<endl;
            pos.push_back(i);
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
        vecLine.clear();
    }

}
