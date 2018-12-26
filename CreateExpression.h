#include "Expression.h"
#include <stack>
#include <string>
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Var.h"
#include "Neg.h"
#include "SymbolTable.h"
#ifndef PROJECT1_CREATEEXPRESSION_H
#define PROJECT1_CREATEEXPRESSION_H

using namespace std;

class CreateExpression {
    SymbolTable* symbols;
    list<Expression*> toDelete;

public:
    CreateExpression(SymbolTable* symbol) {
        this->symbols = symbol;
    }
    Expression* convertToExpression(string string1);
    ~CreateExpression(){
        list<Expression*>::iterator it;
        for(it = toDelete.begin(); it != toDelete.end(); it++){
            delete (*it);
        }
    }
};


#endif //PROJECT1_CREATEEXPRESSION_H