#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"

#ifndef PROJECT1_MUL_H
#define PROJECT1_MUL_H

/**
 * Mul class inheritors Expression, BinaryExpression
 */
class Mul:public Expression,public BineryExpression {
public:
     /**
 * constructor-2 Expressions
 * @param leftArgument Expression
 * @param rightArgument Expression
 */
    Mul(Expression *leftArgument, Expression *rightArgument) : BineryExpression(leftArgument, rightArgument) {
    }
    /**
     * constructor-2 doubles
     * @param leftArgument double
     * @param rightArgument double
     */

    Mul(double leftArgument, double rightArgument) : BineryExpression(new Num(leftArgument), new Num(rightArgument)) {
    }
    /**
     * constructor-double and Expression
     * @param leftArgument double
     * @param rightArgument Expression
     */
    Mul(double leftArgument, Expression *rightArgument) : BineryExpression(new Num(leftArgument), rightArgument) {
    }
        /**
 * constructor- Expression and double
 * @param leftArgument Expression
 * @param rightArgument double
 */
    Mul(Expression *leftArgument, double rightArgument) : BineryExpression(leftArgument, new Num(rightArgument)) {
    }
        /**
     * calculate the value of the mul
     * @param assignment
     * @return the value of calculate
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


#endif //PROJECT1_MUL_H
