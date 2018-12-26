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
/**
 * CreateExpression class.
 */
class CreateExpression {
    //members
    SymbolTable* symbols;
    list<Expression*> toDelete;

public:

     /**
     * constructor
     */
    CreateExpression(SymbolTable* symbol) {
        this->symbols = symbol;
    }
     /**
     * shunting yard
     * @param str the string to make expression
     * @return
     */
    Expression* convertToExpression(string string1);
    /**
    * distructor
    */
    ~CreateExpression(){
        list<Expression*>::iterator it;
        for(it = toDelete.begin(); it != toDelete.end(); it++){
            delete (*it);
        }
    }
};


#endif //PROJECT1_CREATEEXPRESSION_H
