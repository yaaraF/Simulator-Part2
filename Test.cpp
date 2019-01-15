#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "Test.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearche.h"
#include "SeracherExtend.h"
#include "stringReverser.h"
#include"MyClientHandler.h"
#include "MyParallelServer.h"
#include "CacheManager.h"


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








   this->searchable = new MetrixSearchable<vector<int>>(this->metrix,this->start,this->exit,this->matrixStr);
    /*Searcher<vector<int>> *Bfs = new BFS<vector<int>>();
    string sol;
    sol = Bfs->search(mat);*/

   /* Searcher<vector<int>> *Dfs = new DFS<vector<int>>();
    string sol;
    sol = Dfs->search(mat);*/

    /*Searcher<vector<int>> *Best = new BestFirstSearch<vector<int>>();
    string sol;
    sol = Best->search(mat);*/

    Searcher<vector<int>> *astar = new AStar<vector<int>>();
    string sol;
    sol = astar->search(this->searchable);




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

void Test::testParllel() {
    /*Server *testServer=new MyParallelServer();
    CacheManager<string,string> *cacheManager=new FileCacheManager<string,string>();
    Solver <string,string> *rev=new stringReverser();
    ClientHandler *clientHandler=new MyClientHandler();
    testServer->open(5400,clientHandler);
    cout<<"enterToContinue"<<endl;
    cin.ignore();
    testServer->stop();*/

}

void Test::EmpiryTrail() {

    ofstream myFile;
    myFile.open("matrix.txt");


    vector<vector<string>> input;
    vector<string> inside;
    //ניסוי אמפירי
    string res;
    vector<int> start;
    vector<int> end;
    int changeSize = 13;
    int howMany = 0;
    int countLine = 0 ;

        // output each array element's value
        for (int row = 0; row < changeSize; row++) {
            for (int col = 0; col < changeSize; col++) {
                int iSecret = random() % 10 + 1;
                res = to_string(iSecret);
                inside.push_back(res);
            }
            //

            //

            //lineMetrix = split(inside);
            addLineToMetrix(inside, countLine);
            countLine++;
            res.clear();
            inside.clear();
        }
        start.push_back(0);
        start.push_back(0);
        this->start.setState(start);

        end.push_back(changeSize-1);
        end.push_back(changeSize-1);

        this->exit.setState(end);

        for(int j =0 ; j <this->metrix.size();j++){
            for(int k = 0 ; k < this->metrix[j].size();k++){
                State<vector<int>>* now = this->metrix[j][k];

                myFile<<now->getCost();
                myFile<<",";
            }

            myFile<<"\n";

        }

    /*Searchable<vector<int>>* mat = new MetrixSearchable<vector<int>>(this->metrix,this->start,this->exit,this->matrixStr);

    Searcher<vector<int>> *Bfs = new BFS<vector<int>>();
    Searcher<vector<int>> *Dfs = new DFS<vector<int>>();
    Searcher<vector<int>> *Best = new BestFirstSearch<vector<int>>();
    Searcher<vector<int>> *astar = new AStar<vector<int>>();

    string sol;
    sol = Bfs->search(mat);
    sol = Dfs->search(mat);
    sol = Best->search(mat);
    sol = astar->search(mat);*/











}

Test::~Test() {
 delete(this->searchable);
}









