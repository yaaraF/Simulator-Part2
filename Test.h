//
// Created by yaara on 1/3/19.
//

#ifndef PART2_TEST_H
#define PART2_TEST_H

#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "stringReverser.h"

class Test {
void testSerial();
void testReverse();
void testFileMan();
public:
    void testAll();
};


#endif //PART2_TEST_H
