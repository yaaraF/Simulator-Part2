//
// Created by yaara on 1/3/19.
//

#include "Test.h"


void Test::testSerial() {
    MySerialServer tester;
    ClientHandler *clientHandler=new MyTestClientHandler();
    tester.open(5400,clientHandler);


}

void Test::testAll() {
 testFileMan();
}

void Test::testReverse() {
    stringReverser *stringReverser1 = new stringReverser();
    string a = stringReverser1->solve("!@#%");
   cout<<a<<endl;
}

void Test::testFileMan() {
 FileCacheManager <string,string> f;
   // CacheManager <string,string> *fileCacheManager= new FileCacheManager<string,string>();
//  cout<<fileCacheManager->isProblemExist("hello")<<endl;
//    fileCacheManager->saveSolution("hello","bye");
//    cout<<fileCacheManager->isProblemExist("hello")<<endl;


}


