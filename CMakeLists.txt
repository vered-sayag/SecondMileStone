cmake_minimum_required(VERSION 3.13)
project(SecondMiilestone)

set(CMAKE_CXX_STANDARD 14)

add_executable(SecondMiilestone main.cpp Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h MySerialServer.cpp MySerialServer.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverse.h Main.h MyClientHandler.cpp MyClientHandler.h testSolver.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")