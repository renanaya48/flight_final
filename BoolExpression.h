#include "Expression.h"
#include "CreateExpression.h"
#include <map>
#include "SymbolTable.h"
#ifndef PROJECT1_BOOLEXPRESSION_H
#define PROJECT1_BOOLEXPRESSION_H


class BoolExpression  {
    Expression* leftArgument;
    Expression* rightArgument;
    string action;
    SymbolTable* symbols;
public:

    BoolExpression(string stringCondition, SymbolTable* symbol) {
        this->symbols = symbol;
        this->createBoolExpression(stringCondition);
    }

    void createBoolExpression(string conditionToCheck);
    bool calculateBool(map <string,double> symbolMap);

    ~BoolExpression(){}

};

#endif //PROJECT1_BOOLEXPRESSION_H