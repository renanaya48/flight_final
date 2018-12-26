#include "Expression.h"

#ifndef PROJECT1_NEG_H
#define PROJECT1_NEG_H


/**
 * Neg class inheritors Expression
 */
class Neg : public Expression {
public:
    //member
    Expression *negativeNumber;
    /**
     * constructor
     * @param negativeNumber Expression
     */
    Neg(Expression *negativeNumber);
/**
 * calculate the neg of the number
 * @param assignment map
 * @return the neg number
 */
    virtual double calculate(map<string, double> &assignment);

    /**
 *
 * @return the neg number
 */
    virtual double calculate();

};


#endif //PROJECT1_NEG_H
