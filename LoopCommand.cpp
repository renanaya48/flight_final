#include "LoopCommand.h"

/**
 * execute
 * @param script  the iterator
 * @return 0 when finish
 */
int LoopCommand::execute(vector<string>::iterator &vectorIt) {
    list<CommandExpression*> tempList;
    //get the commands to do 
    while (this->boolExpression->calculateBool(
            this->symbolTable->getSymbols())) {
        tempList = this->commandExpressions;
        list<CommandExpression *>::iterator itr;
        //for all the commands in the list
        for (itr = tempList.begin();
             itr !=tempList.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            //execute the command
            (*itr)->calculate(symbolMap);
        }
    }
}
