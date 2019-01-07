//
// Created by davidregev on 31/12/18.
//

#ifndef SECONDMIILESTONE_MYSERIALSERVER_H
#define SECONDMIILESTONE_MYSERIALSERVER_H

#include "server_side.h"
#include "ClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {
public:
    MySerialServer(ClientHandler c) : Server(c);

    virtual void open(int port);

    virtual void stop();

    static void* thread_OpenDataServer(void* arg);

};

typedef struct {
    int port;
    ClientHandler* client;
} TCPDataServer;



#endif //SECONDMIILESTONE_MYSERIALSERVER_H
