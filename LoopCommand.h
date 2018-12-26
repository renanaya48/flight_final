#include "Command.h"
#include "map"
#include "CommandExpression.h"
#include <list>
#include "BoolExpression.h"
#include "SymbolTable.h"


#ifndef PROJECTNUM1_LOOPCOMMAND_H
#define PROJECTNUM1_LOOPCOMMAND_H

/**
*LoopCommand class
*/
class LoopCommand : public Command  {
    //members
    BoolExpression* boolExpression;
    list<CommandExpression*> commandExpressions;
    SymbolTable* symbolTable;

public:
        /**
     * constructor
     * @param boolExpres  BoolExpression
     * @param list list<CommandExpression *>
     * @param symbolTable  SymbolTable
     */
    LoopCommand(BoolExpression *boolExpres,
                             list<CommandExpression *> list,
                             SymbolTable *symbolTable) {
        this->boolExpression = boolExpres;
        this->commandExpressions = list;
        this->symbolTable = symbolTable;
    }
     /**
     * set the map
     * @param cMap  the map to change
     */
    void setCommandsMap(map <string,Command*> cMap);
       /**
     * execute
     * @param script  the iterator
     * @return 0 when finish
     */
    virtual int execute(vector<string>::iterator &vectorIt);
};


#endif //PROJECTNUM1_LOOPCOMMAND_H
