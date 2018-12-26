#include <string>
#include <vector>

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <map>
#include <mutex>

using namespace std;

class Command {
public:
    map<string, double> symbolTable;
public:
    Command(){}
    virtual int execute(vector<string>::iterator &vectorIt) = 0;

    ~Command(){}
};

#endif //PROJECT1_COMMAND_H
