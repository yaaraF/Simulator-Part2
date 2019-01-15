cmake_minimum_required(VERSION 3.12)
project(part2)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(part2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Test.cpp Test.h stringReverser.h stringReverser.cpp Searcher.h Searchable.h State.h BFS.h MetrixSearchable.h CheckTemplete.h DFS.h SeracherExtend.h MyPriorityQueue.h BestFirstSearche.h MyClientHandler.cpp MyClientHandler.h MyParallelServer.cpp MyParallelServer.h AStar.h RunTheProgram.cpp RunTheProgram.h)