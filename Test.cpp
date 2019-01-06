//
// Created by yaara on 1/3/19.
//

#include <thread>
#include <iostream>
#include "Test.h"
using namespace std;


void Test::testSerial() {
    MySerialServer tester;
    ClientHandler *clientHandler=new MyTestClientHandler();
    tester.open(5400,clientHandler);


}

void Test::testAll() {
    tryToOpenAThred();
}

void Test::testReverse() {
    stringReverser *stringReverser1 = new stringReverser();
    string a = stringReverser1->solve("!@#%");
   cout<<a<<endl;
}

void Test::testFileMan() {
    CacheManager <string,string> *fileCacheManager= new FileCacheManager<string,string>();
  cout<<fileCacheManager->isProblemExist("bye")<<endl;
    fileCacheManager->saveSolution("hello","bye");
    cout<<fileCacheManager->isProblemExist("hello")<<endl;


}

void Test::tryToOpenAThred() {

    thread thread1(printFromTHeThread);
    thread1.detach();
}

void Test::printFromTHeThread() {
        int i = 0;
        while(i < 20){
            cout<<i<<endl;
            i++;
        }
}
