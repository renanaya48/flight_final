#include "Expression.h"

#ifndef PROJECT1_NEG_H
#define PROJECT1_NEG_H


class Neg : public Expression {
public:
    Expression *negativeNumber;

    Neg(Expression *negativeNumber);

    virtual double calculate(map<string, double> &assignment);

    virtual double calculate();

};


#endif //PROJECT1_NEG_H