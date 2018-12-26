#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H

#include "ConditionParser.h"
#include "CommandExpression.h"
#include "BoolExpression.h"
#include "SymbolTable.h"

/**
 * ifCommand class inheritors ConditionParser
 */
class IfCommand: public ConditionParser {
    //members
    list<CommandExpression*> commandExpressions;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;

public:
     /**
     * constructor
     * @param boolExpres boolExpression
     * @param listExp commandExpressions
     * @param symbolTable symbolTable
     */
    IfCommand(BoolExpression *boolExpres, list<CommandExpression*> listExp, SymbolTable* symbolTable) {
        this->commandExpressions = listExp;
        this->boolExpression = boolExpres;
        this->symbolTable=symbolTable;
    }
        /**
     * if the condition true- do the next.
     * @param script the iterator
     * @return 0 when finish
     */
    virtual int execute(vector<string>::iterator &vectorIt);
    /**
    * distructor
    */
    ~IfCommand(){}

};


#endif //PROJECT1_IFCOMMAND_H
