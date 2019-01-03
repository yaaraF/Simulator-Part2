//
// Created by yaara on 1/3/19.
//

#include "Test.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

void Test::testSerial() {
    MySerialServer tester;
    ClientHandler *clientHandler=new MyTestClientHandler();
    tester.open(5400,clientHandler);

}

void Test::testAll() {
 testSerial();
}
