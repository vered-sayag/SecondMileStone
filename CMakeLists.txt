cmake_minimum_required(VERSION 3.13)
project(SecondMiilestone)

set(CMAKE_CXX_STANDARD 14)

add_executable(SecondMiilestone main.cpp DFSSearcher.h StackDB.h Server.h AStarSearcher.h BFSSearcher.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h MySerialServer.cpp MySerialServer.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverse.h Main.h MyClientHandler.cpp MyClientHandler.h MyParallelServer.cpp MyParallelServer.h MyTCPserver.cpp MyTCPserver.h MatrixSearchable.cpp MatrixSearchable.h Searchable.h Searcher.h State.h SearchSolver.h BestFirstSearcher.h MyPriorityQueue.h SearchSolver.h PriorityQueueDB.h DBtoSearcher.h TraceBackSearcher.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")