#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "SymbolTable.h"
#include "CommandExpression.h"
#include "CommandMap.h"
#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


class ConditionParser : public Command {
    list<CommandExpression *> expressionCommandList;
    CommandMap* commandMap;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;

public:
    ConditionParser(){}

    ConditionParser(CommandMap* commandMap,SymbolTable* symbolMap);

    virtual int execute(vector<string>::iterator &vectorIt);
    void createCommand(vector<string>::iterator &vectorIt);

    ~ConditionParser(){}
};


#endif //PROJECTNUM1_CONDITIONPARSER_H