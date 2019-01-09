#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include "Test.h"
#include "BFS.h"

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

        string line;
        if(!table.eof()) {
          //line = "";
            getline(table, line);
        }else{
            break;
        }




    ////////////////////

        // If connection is established then start communicating

        if(strcmp(line.c_str(),"end") != 0 ){
            if(!afterEnd) {
                lineMetrix = split(line);
                addLineToMetrix(lineMetrix, countLine);
                countLine++;
            }else{
                lineMetrix = split(line);
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
        if(strcmp(line.c_str(),"end") == 0){
            afterEnd=true;
        }
        /*if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }*/
    }

   Searcher<vector<int>> *searcher = new BFS<vector<int>>();
    Searchable<vector<int>>* mat = new MetrixSearchable<vector<int>>(this->metrix,this->start,this->exit);


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

Test::Test() {

}









