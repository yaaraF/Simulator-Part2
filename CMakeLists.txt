cmake_minimum_required(VERSION 3.12)
project(part2)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(part2 main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Test.cpp Test.h stringReverser.h stringReverser.cpp Searcher.h Searchable.h State.cpp State.h BFS.cpp BFS.h MetrixSearchable.cpp MetrixSearchable.h CheckTemplete.h DFS.cpp DFS.h SeracherExtend.h MyPriorityQueue.h BestFirstSearche.h MyClientHandler.cpp MyClientHandler.h MyParallelServer.cpp MyParallelServer.h AStar.h)