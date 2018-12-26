
#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"
#ifndef PROJECT1_DIV_H
#define PROJECT1_DIV_H

class Div : public Expression,public BineryExpression {

public:
    Div(double leftArgument, Expression *rightArgument) : BineryExpression(new Num(leftArgument), rightArgument) {
    }
    Div(Expression *leftArgument, double rightArgument) : BineryExpression(leftArgument, new Num(rightArgument)) {
    }
    Div(Expression *leftArgument, Expression *rightArgument):BineryExpression(leftArgument, rightArgument) { }

    Div(double leftArgument, double rightArgument) : BineryExpression(new Num(leftArgument), new Num(rightArgument)) {
    }

    virtual double calculate(map<string, double> &assignment) ;

    virtual double calculate() ;
    ~Div(){}

};


#endif //PROJECT1_DIV_H
