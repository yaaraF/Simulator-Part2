#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "Test.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearche.h"
#include "SeracherExtend.h"

using namespace std;

void Test::handlerClient(int clientId) {
    int clilen;
    ssize_t n;
    vector<string> lineMetrix;
    vector<int> state;
    int countLine=0;
    bool afterEnd=false;
    bool wasStart=false;
    bool wasExit=false;

    fstream table;
    table.open("test.txt", fstream::in | fstream::out | fstream::app);
    if (table.fail()) {
        throw "Failed in opening file";
    }

    while(!wasExit) {

        string buffer;
        if(!table.eof()) {
          //line = "";
            getline(table, buffer);
        }else{
            break;
        }




    ////////////////////

        // If connection is established then start communicating

        if (strcmp(buffer.c_str(), "end") != 0) {
            if (!afterEnd) {
                this->matrixStr += buffer;
                this->matrixStr+="$";
                lineMetrix = split(buffer);
                addLineToMetrix(lineMetrix, countLine);
                countLine++;
            } else {
                lineMetrix = split(buffer);
                state.push_back(stoi(lineMetrix[0]));
                state.push_back(stoi(lineMetrix[1]));
                if (!wasStart) {
                    if (state[0] < 0 || state[1] < 0 || state[0] > this->metrix.size()
                        || state[1] > this->metrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    this->matrixStr += buffer;
                    wasStart = true;
                    this->start.setState(state);
                    state.clear();
                } else {
                    if (state[0] < 0 || state[1] < 0 || state[0] > this->metrix.size()
                        || state[1] > this->metrix[state[0]].size()) {
                        throw "not valid exit state";
                    }
                    this->matrixStr += buffer;
                    wasExit = true;
                    this->exit.setState(state);
                    state.clear();
                }
            }
        } else {
            afterEnd = true;
        }

    }

   Searcher<vector<int>> *searcher = new AStar<vector<int>>();

    Searchable<vector<int>>* mat = new MetrixSearchable<vector<int>>(this->metrix,this->start,this->exit,this->matrixStr);
    State<vector<int>> *begin = mat->getInitalState();
   cout<<begin->getState()[0]<<begin->getState()[1]<<endl;
   State<vector<int>> *end = mat->getGoalState();


   cout<<end->getState()[0]<<end->getState()[1]<<endl;
    cout<<begin->getState()[0]<<begin->getState()[1]<<endl;
    vector<State<vector<int>>*> close = mat->getAllPossibleStates(begin);
    string solution;
    if (!this->cm->isProblemExist(this->matrixStr)) {
        solution = searcher->search(mat);
        this->cm->saveSolution(this->matrixStr, solution);
    } else {
        this->writeTheSolution(clientId, this->matrixStr.c_str());
    }
    //string hello = searcher->search(mat);
   cout<<solution<<endl;



}

vector<string> Test::split(string line){
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

void Test::addLineToMetrix(vector<string> line, int iCounter) {

    vector<State<vector<int>>*> t;
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

        t.push_back(myState);
        pos.clear();
    }
    this->metrix.push_back(t);
}

void Test::writeTheSolution(int id, const char* problem) {
    string solution = this->cm->getSolution(problem);
    cout<<"hiii "<<endl;
    cout<<solution<<endl;
   /* ssize_t n = write(id, solution.c_str(), 1024);

    if (n < 0) {
        perror("ERROR writing to socket");
        //exit(1);
    }*/
}

Test::Test() {
    this->cm=new FileCacheManager<string,string>();
}

void Test::checkRQ() {


    /*MyPriorityQueue<int> *myPriorityQueue = new
    State<int> *first = new State<int>(1,0,false);
    State<int> *second = new State<int>(2,0,false);
    second->setPathCost(8);
    State<int> *thired = new State<int>(3,0,false);
    thired->setPathCost(-1);
    //State<int> *first = new State<int>(1,0,false);
    myPriorityQueue->add(first);
    myPriorityQueue->add(second);
    myPriorityQueue->add(thired);
   myPriorityQueue->updatePriority(second,thired);
    myPriorityQueue->print();*/




}









