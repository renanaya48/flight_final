#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "SymbolTable.h"
#include "CommandExpression.h"
#include "CommandMap.h"
#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


/**
 * ConditionParser inheritors Command
 */
class ConditionParser : public Command {
    //members
    list<CommandExpression *> expressionCommandList;
    CommandMap* commandMap;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;

public:
    /**
    * constructor
    */
    ConditionParser(){}
    /**
    * constructor
    */
    ConditionParser(CommandMap* commandMap,SymbolTable* symbolMap);
      /**
     * parser the condition
     * @param script iterator
     * @return 0 when finish
     */
    virtual int execute(vector<string>::iterator &vectorIt);
     /**
     * create new command
     * @param vectorIt the iterator
     */
    void createCommand(vector<string>::iterator &vectorIt);
    /**
    *distructor
    */
    ~ConditionParser(){}
};


#endif //PROJECTNUM1_CONDITIONPARSER_H
