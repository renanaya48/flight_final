#include "Command.h"
#include "map"
#include "CommandExpression.h"
#include <list>
#include "BoolExpression.h"
#include "SymbolTable.h"


#ifndef PROJECTNUM1_LOOPCOMMAND_H
#define PROJECTNUM1_LOOPCOMMAND_H


class LoopCommand : public Command  {
    BoolExpression* boolExpression;
    list<CommandExpression*> commandExpressions;
    SymbolTable* symbolTable;

public:
    LoopCommand(BoolExpression *boolExpres,
                             list<CommandExpression *> list,
                             SymbolTable *symbolTable) {
        this->boolExpression = boolExpres;
        this->commandExpressions = list;
        this->symbolTable = symbolTable;
    }
    void setCommandsMap(map <string,Command*> cMap);
    virtual int execute(vector<string>::iterator &vectorIt);
};


#endif //PROJECTNUM1_LOOPCOMMAND_H