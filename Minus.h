#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"

#ifndef PROJECT1_MINUS_H
#define PROJECT1_MINUS_H


class Minus: public Expression, public BineryExpression {
public:
    Minus(Expression *leftArgument, Expression *rightArgument) : BineryExpression(leftArgument, rightArgument) {
    }

    Minus(double leftArgument, double rightArgument) : BineryExpression(new Num(leftArgument), new Num(rightArgument)) {
    }

    Minus(double leftArgument, Expression *rightArgument) : BineryExpression(new Num(leftArgument), rightArgument) {
    }
    Minus(Expression *leftArgument, double rightArgument) : BineryExpression(leftArgument, new Num(rightArgument)) {
    }
    virtual double calculate(map<string, double> &assignment) ;

    /**
     * A convenience method ,evaluate(assignment)`same to the evaluate method above,
     * but this methods use in empty assignment.
     *
     * @return the result of the expression using
     * @throws Exception if the expression contains a variable which is not in the assignment, an exception is thrown.
     */
    virtual double calculate() ;
};


#endif //PROJECT1_MINUS_H
