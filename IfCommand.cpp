#include "IfCommand.h"

int IfCommand::execute(vector<string>::iterator &vectorIt) {
    if (this->boolExpression->calculateBool(this->symbolTable->getSymbols())) {
        list<CommandExpression *>::iterator tempIt;

        for (tempIt = this->commandExpressions.begin();
             tempIt != this->commandExpressions.end(); tempIt++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*tempIt)->calculate(symbolMap);
        }
    }
}