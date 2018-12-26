#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H

#include "ConditionParser.h"
#include "CommandExpression.h"
#include "BoolExpression.h"
#include "SymbolTable.h"

class IfCommand: public ConditionParser {
    list<CommandExpression*> commandExpressions;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;

public:
    IfCommand(BoolExpression *boolExpres, list<CommandExpression*> listExp, SymbolTable* symbolTable) {
        this->commandExpressions = listExp;
        this->boolExpression = boolExpres;
        this->symbolTable=symbolTable;
    }
    virtual int execute(vector<string>::iterator &vectorIt);
    ~IfCommand(){}

};


#endif //PROJECT1_IFCOMMAND_H
