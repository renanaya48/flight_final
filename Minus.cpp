
#include "Minus.h"
/**
 * calculate the expression
 * @param assignment
 * @return
 */
double Minus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    //get the expressions values
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    //return the value after minus
    return leftValue-rightValue;
}
/**
 * A convenience method ,evaluate(assignment)`same to the evaluate method above,
 * but this methods use in empty assignment.
 *
 * @return the result of the expression using
 */
double Minus::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}
