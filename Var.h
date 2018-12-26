#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H

#include <string>
#include "Expression.h"
#include "SymbolTable.h"
class Var: public Expression {
    string var;
    SymbolTable* symbols;
public:
    Var(string v, SymbolTable* symbol);
    virtual double calculate(map<string, double> &assignment);

    double calculate();

};

#endif //PROJECT1_VAR_H
