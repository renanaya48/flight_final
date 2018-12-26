#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"

#ifndef PROJECT1_MINUS_H
#define PROJECT1_MINUS_H

/**
 * Minus class inheritors Expression, BinaryExpression
 */
class Minus: public Expression, public BineryExpression {
public:
        /**
     * constructor-2 Expressions
     * @param leftArgument Expression
     * @param rightArgument Expression
     */
    Minus(Expression *leftArgument, Expression *rightArgument) : BineryExpression(leftArgument, rightArgument) {
    }
         /**
     * constructor-2 doubles
     * @param leftArgument double
     * @param rightArgument double
     */
    Minus(double leftArgument, double rightArgument) : BineryExpression(new Num(leftArgument), new Num(rightArgument)) {
    }
        /**
     * constructor-double and Expression
     * @param leftArgument double
     * @param rightArgument Expression
     */

    Minus(double leftArgument, Expression *rightArgument) : BineryExpression(new Num(leftArgument), rightArgument) {
    }
        /**
     * constructor- Expression and double
     * @param leftArgument double
     * @param rightArgument Expression
     */
    Minus(Expression *leftArgument, double rightArgument) : BineryExpression(leftArgument, new Num(rightArgument)) {
    }
        /**
     * calculate the expression
     * @param assignment
     * @return
     */
    virtual double calculate(map<string, double> &assignment) ;

    /**
     * A convenience method ,evaluate(assignment)`same to the evaluate method above,
     * but this methods use in empty assignment.
     *
     * @return the result of the expression using
     */
    virtual double calculate() ;
};


#endif //PROJECT1_MINUS_H
