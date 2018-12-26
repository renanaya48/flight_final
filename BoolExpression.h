#include "Expression.h"
#include "CreateExpression.h"
#include <map>
#include "SymbolTable.h"
#ifndef PROJECT1_BOOLEXPRESSION_H
#define PROJECT1_BOOLEXPRESSION_H

/**
* BoolExpression class
*/
class BoolExpression  {
    //members
    Expression* leftArgument;
    Expression* rightArgument;
    string action;
    SymbolTable* symbols;
public:
/**
 * constructor
 * @param stringCondition the condition by string
 * @param symbol the symbolTable
 */
    BoolExpression(string stringCondition, SymbolTable* symbol) {
        this->symbols = symbol;
        this->createBoolExpression(stringCondition);
    }
     /**
 * the function gets a condition in string and makes it to expression.
 * @param boolCondition the condition
 */
    void createBoolExpression(string conditionToCheck);
  /**
 * the function calculate the condition and returns the answer
 * @param symbolMap the symbol map
 * @return true / false according to the condition
 */
    bool calculateBool(map <string,double> symbolMap);

   /**
   * dicractor
   */
    ~BoolExpression(){}

};

#endif //PROJECT1_BOOLEXPRESSION_H
