//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_MYSERIALSERVER_H
#define SECONDMIILESTONE_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

using namespace server_side;
namespace server_side {
    class MySerialServer : public Server {
        pthread_t trid;
        bool shouldStop = 0;
    public:
        MySerialServer(ClientHandler *c) : Server(c) {}

        void open(int port);

        void stop();

        static void *thread_OpenDataServer(void *arg);

    };

    typedef struct {
        int port;
        bool *shouldStop;
        ClientHandler *client;
    } TCPDataServer;

}


#endif //SECONDMIILESTONE_MYSERIALSERVER_H
