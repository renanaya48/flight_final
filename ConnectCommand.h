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
#include "string"
#include "CheckConnection.h"
#include "StringFlightControls.h"
#include "ExitServer.h"

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H

using namespace std;

class ConnectCommand : public Command {
    CheckConnection* isConnected;
    StringFlightControls* flightString;
    ExitServer* toExit;

public:
    ConnectCommand(CheckConnection* check, StringFlightControls* flightStr, ExitServer* exit);
    virtual int execute(vector<string>::iterator &vectorIt);
    ~ConnectCommand(){}
};

#endif //PROJECT1_CONNECTCOMMAND_H
