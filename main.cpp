#include <iostream>
#include <chrono>
#include <thread>
#include "FileCacheManager.h"
#include "server_side.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverse.h"

using namespace server_side;

int main() {
    Server *server = new MySerialServer(new MyTestClientHandler(new StringReverse, new FileCacheManager("test2.txt")));
    server->open(5400);
    this_thread::sleep_for(chrono::milliseconds(100000));
    server->stop();

    return 0;
}