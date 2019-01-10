#include "Main.h"
#include "testSolver.h"
#include "MyClientHandler.h"

int main(int numArg, char *args[]) {

//server_side::boot::Main::main(numArg,args);
    Server *server = new MySerialServer();
    server->open(atoi(args[1]),new MyClientHandler(new testSolver(), new FileCacheManager("test3.txt")));
    this_thread::sleep_for(chrono::milliseconds(10000));
    server->stop();
    delete (server);
    return 0;
}
