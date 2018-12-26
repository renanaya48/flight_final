#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include <vector>
#include <pthread.h>
#include "CheckConnection.h"
#include "ExitServer.h"

#ifndef PROJECT1_OPENSERVERCOMMAND_H
#define PROJECT1_OPENSERVERCOMMAND_H

#include "FlightValueMap.h"

using namespace std;

class OpenServerCommand : public Command {
    CheckConnection* isConnected;
    FlightValueMap* valueMap;
    ExitServer* toExit;

public:
    OpenServerCommand(CheckConnection* check, FlightValueMap* vaules, ExitServer* exit);
    virtual int execute(vector<string>::iterator &vectorIt);
};


#endif //PROJECT1_OPENSERVERCOMMAND_H
