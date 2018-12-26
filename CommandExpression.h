#ifndef PROJECT1_COMMANDEXPRESSION_H
#define PROJECT1_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "CreateExpression.h"
#include "SymbolTable.h"

/**
 * CommandExpression class inheritors Expression
 */
class CommandExpression: public Expression {
    //members
    Command* command;
    vector<string>::iterator vectorIt;
    SymbolTable* symbols;


public:
    /**
     * constructor.
     * @param it  iterator
     * @param command1 Command
     */    
    CommandExpression(vector<string>::iterator &it, Command* command1, SymbolTable* symbol){
        this->command = command1;
        this->vectorIt = it;
        this->symbols = symbol;
    }
/**
 * calculate the value of the expression
 * @return the value after calculate
 */
    double calculate();
    /**
 *
 * @param assignment map
 * @return the result of the expression in numbers
 */
    double calculate(map<string, double> &assignment);
/**
* distructor
*/
    ~CommandExpression(){}
};


#endif //PROJECT1_COMMANDEXPRESSION_H
