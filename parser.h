#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H

#include <map>
#include "Command.h"
#include <vector>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "SymbolTable.h"
#include "CheckConnection.h"
#include "FlightValueMap.h"
#include "PathMap.h"
#include "StringFlightControls.h"
#include "CommandMap.h"
#include "ConditionParser.h"
#include "SleepCommand.h"
#include "ExitServer.h"

using namespace std;


class parser {
    CommandMap* commands;
    SymbolTable* symbols;
    CheckConnection* connection;
    FlightValueMap* valueMap;
    PathMap* bindMap;
    StringFlightControls* stringControl;
    ExitServer* toExit;
    list<Expression*> toDelete;

public:
    parser();
    void runParser(vector<string> v);

    ~parser(){
        delete this->stringControl;
        delete this->connection;
        delete this->valueMap;
        delete this->bindMap;
        delete this->symbols;
        delete this->toExit;
        map<string, Command *> tempMap = this->commands->getCommandMap();
        map<string, Command *>::iterator it;
        for (it = tempMap.begin(); it != tempMap.end(); it++){
                delete (it)->second;
        }
        delete this->commands;

        list<Expression*>::iterator itr;
        for(itr = toDelete.begin(); itr != toDelete.end(); itr++){
            delete (*itr);
        }
    }
};


#endif //PROJECT1_PARSER_H
