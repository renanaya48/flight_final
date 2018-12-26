#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"
#ifndef PROJECT1_PLUS_H
#define PROJECT1_PLUS_H

/**
 * Plus class inheritors Expression, BinaryExpression
 */
class Plus : public Expression,public BineryExpression {
public:
     /**
 * constructor-2 Expressions
 * @param leftArgument Expression
 * @param rightArgument Expression
 */
    Plus(Expression *leftArgument, Expression *rightArgument) : BineryExpression(leftArgument, rightArgument
                                                                                 ) {
    }
 /**
 * constructor-2 double
 * @param leftArgument double
 * @param rightArgument double
 */
    Plus(double leftArgument, double rightArgument) : BineryExpression(new Num(leftArgument), new Num(rightArgument)
                                                                       ) {
    }
    /**
     * constructor-double and Expression
     * @param leftArgument double
     * @param rightArgument Expression
     */
    Plus(double leftArgument, Expression *rightArgument) : BineryExpression(new Num(leftArgument), rightArgument
                                                                            ) {
    }
        /**
 * constructor- Expression and double
 * @param leftArgument Expression
 * @param rightArgument double
 */
    Plus(Expression *leftArgument, double rightArgument) : BineryExpression(leftArgument, new Num(rightArgument)
                                                                            ) {
    }
        /**
     * calculate the value of the plus
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


#endif //PROJECT1_PLUS_H
