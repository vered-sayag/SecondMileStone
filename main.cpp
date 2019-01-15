#include "Main.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "SearchSolver.h"
#include "BestFirstSearcher.h"
int main(int numArg, char *args[]) {

//server_side::boot::Main::main(numArg,args);
    if (numArg == 2 && regex_match(args[1], regex("^\\d+"))) {
    Server *server = new MyParallelServer();
    server->open(atoi(args[1]),new MyClientHandler(new SearchSolver(),new FileCacheManager("test3.txt")));
    this_thread::sleep_for(chrono::milliseconds(10000));
    server->stop();
    delete (server);
    } else {
        throw invalid_argument("Invalid main arguments");
    }
    return 0;
}
