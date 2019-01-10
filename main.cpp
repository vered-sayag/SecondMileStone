#include "Main.h"
#include "testSolver.h"
#include "MyClientHandler.h"

int main(int numArg, char *args[]) {

//server_side::boot::Main::main(numArg,args);
    Server *server = new MySerialServer(
            new MyClientHandler(new testSolver, new FileCacheManager("test3.txt")));
    server->open(atoi(args[1]));
    this_thread::sleep_for(chrono::milliseconds(100000));
    server->stop();
    return 0;
}
