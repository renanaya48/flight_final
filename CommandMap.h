#include "Command.h"
#include "map"

#ifndef PROJECTNUM1_COMMANDMAP_H
#define PROJECTNUM1_COMMANDMAP_H


class CommandMap {
    map<string, Command*> commandMAp;

public:
    CommandMap(){}
    void addCommand(string key,Command* command);
    Command* getCommand(string key);
    map<string, Command*> getCommandMap();
    bool isInMap(string key);
    ~CommandMap(){}
};


#endif //PROJECTNUM1_COMMANDMAP_H
