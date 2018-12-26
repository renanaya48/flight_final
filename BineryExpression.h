#ifndef PROJECT1_BINERYEXPRESSION_H
#define PROJECT1_BINERYEXPRESSION_H

#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include "Expression.h"
//BineryExpression class
class BineryExpression {
protected:
    //members
    Expression *leftArgument;
    Expression *rightArgument;

public:
       /**
     * The BinaryExpression constructor by two expression and operator.
     *
     * @param leftArgument  the left side argument
     * @param rightArgument the right side argument
     * @param operator      string of the class.
     */
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
