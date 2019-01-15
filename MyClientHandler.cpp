
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "MyClientHandler.h"
#include <mutex>
#include "FileCacheManager.h"

using namespace std;

void MyClientHandler::handlerClient(int clientId) {
    ssize_t n;
    string matrixStr;
    vector<vector<State<vector<int>> *>> matrix;
    State<vector<int>> start;
    State<vector<int>> exit;
    vector<string> lineMetrix;
    vector<vector<string>> tempMatrix;
    vector<int> state;
    bool wasEnd = false;

    while (!wasEnd) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientId, buffer, 1000);
        if (n < 0) {
            perror("ERROR reading from socket");
        }
        if (strcmp(buffer, "end") != 0) {
            matrixStr += buffer;
            matrixStr += "$";
            lineMetrix = split(buffer);
            tempMatrix.push_back(lineMetrix);
            lineMetrix.clear();
        } else {
            wasEnd = true;
            createMatrix(tempMatrix, matrix);
            for (int i = tempMatrix.size() - 2; i < tempMatrix.size(); ++i) {
                lineMetrix = tempMatrix[i];
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if (state[0] < 0 || state[1] < 0 || state[0] > matrix.size()
                    || state[1] > matrix[state[0]].size()) {
                    throw "not valid state";
                }
                if (i == tempMatrix.size() - 2) {
                    start.setState(state);
                } else {
                    exit.setState(state);
                }
                state.clear();
            }
        }
    }
    mutex mutex1;
    mutex1.lock();
    if (!cm->isProblemExist(matrixStr)) {
        this->matrixSrc = new MetrixSearchable<vector<int>>(matrix, start, exit, matrixStr);
        string solution = searcher->solve(this->matrixSrc);
        cm->saveSolution(matrixStr, solution);
    } else {
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


void MyClientHandler::writeTheSolution(int id, const char *problem) {
    string solution = cm->getSolution(problem);
    ssize_t n = write(id, solution.c_str(), solution.size());

    if (n < 0) {
        perror("ERROR writing to socket");
    }
}

void MyClientHandler::createMatrix(vector<vector<string>> lines, vector<vector<State<vector<int>> *>> &matrix) {
    int temp;
    vector<int> pos;
    vector<State<vector<int>> *> vecLine;
    for (int i = 0; i < lines.size() - 2; ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {

            if (strcmp(lines[i][j].c_str(), "-1") == 0) {
                temp = -1;
            } else {
                temp = stoi(lines[i][j]);
            }
            pos.push_back(i);
            pos.push_back(j);
            this->myState = new State<vector<int>>(pos, temp, false);
            vecLine.push_back(this->myState);
            pos.clear();
        }
        matrix.push_back(vecLine);
        vecLine.clear();
    }

}

MyClientHandler::MyClientHandler(CacheManager<string, string> *cm,
                                 Solver<Searchable<vector<int>> *, string> *searcher) {
    this->cm = cm;
    this->searcher = searcher;
}

MyClientHandler::~MyClientHandler() {
    delete (this->matrixSrc);
    delete (this->myState);
}
