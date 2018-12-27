#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H

#include <string>
#include "Expression.h"
#include "SymbolTable.h"
/**
 * Var class inheritors Expression
 */
class Var: public Expression {
    //members
    string var;
    SymbolTable* symbols;
public:
     /**
     * constructor
     * @param v string
     */
    Var(string v, SymbolTable* symbol);
     /**
     * calculate
     * @param assignment map
     * @return the value
     */
    virtual double calculate(map<string, double> &assignment);
    /**
     * 
     * @return the value
     */
    double calculate();

};

#endif //PROJECT1_VAR_H
