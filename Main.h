//
// Created by vered on 09/01/19.
//

#ifndef SECONDMIILESTONE_BOOT_H
#define SECONDMIILESTONE_BOOT_H

#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include "FileCacheManager.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverse.h"

namespace server_side {
    namespace boot {
        class Main {
        public:
            static int main(int numArg, char *args[]) {

                if (numArg == 2 && regex_match(args[1], regex("^\\d+")) ) {
                    Server *server = new MySerialServer(
                            new MyTestClientHandler(new StringReverse, new FileCacheManager("test2.txt")));
                    server->open(atoi(args[1]));
                    this_thread::sleep_for(chrono::milliseconds(10000));
                    server->stop();
                    delete (server);
                } else {
                    throw invalid_argument("Invalid main arguments");
                }

                return 0;
            }
        };
    }
}
#endif //SECONDMIILESTONE_BOOT_H
