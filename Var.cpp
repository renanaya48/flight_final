#include "Var.h"

Var::Var(string v, SymbolTable* symbol) {
    this->var = v;
    this->symbols = symbol;
}

double Var::calculate(map<string, double> &assignment) {
    if(this->symbols->isInSymbol(this->var)){
        return this->symbols->getValue(this->var);
    } else {
        throw "error: no such variable";
    }
}

double Var::calculate() {
    map<string, double> temp;
    calculate(temp);
}