cmake_minimum_required(VERSION 3.13)
project(part2)

set(CMAKE_CXX_STANDARD 14)

add_executable(part2 main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h)