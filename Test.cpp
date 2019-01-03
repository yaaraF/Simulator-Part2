//
// Created by yaara on 1/3/19.
//

#include "Test.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "stringReverser.h"

void Test::testSerial() {
    MySerialServer tester;
    ClientHandler *clientHandler=new MyTestClientHandler();
    tester.open(5400,clientHandler);


}

void Test::testAll() {
 testReverse();
}

void Test::testReverse() {
    stringReverser *stringReverser1 = new stringReverser();
    string a = stringReverser1->solve("!@#%");
   cout<<a<<endl;
}


