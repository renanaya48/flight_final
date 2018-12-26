#ifndef PROJECT1_BINERYEXPRESSION_H
#define PROJECT1_BINERYEXPRESSION_H

#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include "Expression.h"
class BineryExpression {
protected:
    Expression *leftArgument;
    Expression *rightArgument;

public:
    BineryExpression(Expression *leftArgument, Expression *rightArgument) {
        this->leftArgument = leftArgument;
        this->rightArgument = rightArgument;
    }
    /**
     * distructor
     */
    ~BineryExpression(){}
};
#endif //PROJECT1_BINERYEXPRESSION_H
