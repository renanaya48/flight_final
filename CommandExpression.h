#ifndef PROJECT1_COMMANDEXPRESSION_H
#define PROJECT1_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "CreateExpression.h"
#include "SymbolTable.h"

class CommandExpression: public Expression {
    Command* command;
    vector<string>::iterator vectorIt;
    SymbolTable* symbols;


public:
    CommandExpression(vector<string>::iterator &it, Command* command1, SymbolTable* symbol){
        this->command = command1;
        this->vectorIt = it;
        this->symbols = symbol;
    }

    double calculate();
    double calculate(map<string, double> &assignment);

    ~CommandExpression(){}
};


#endif //PROJECT1_COMMANDEXPRESSION_H
