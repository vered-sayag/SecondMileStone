#include "Main.h"
#include "testSolver.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"

int main(int numArg, char *args[]) {

//server_side::boot::Main::main(numArg,args);
    Server *server = new MyParallelServer();
    server->open(atoi(args[1]),new MyTestClientHandler(new StringReverse(), new FileCacheManager("test2.txt")));
    this_thread::sleep_for(chrono::milliseconds(100));
    server->stop();
    delete (server);
    return 0;
}
