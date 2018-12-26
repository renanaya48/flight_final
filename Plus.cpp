#include "Plus.h"
/**
 * calculate the expression
 * @param assignment map
 * @return the calculate of the experession
 */
double Plus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    //get the value of the right and left expressions
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    //return the plus expression
    return leftValue+rightValue;
}
/**
 * A convenience method ,evaluate(assignment)`same to the evaluate method above,
 * but this methods use in empty assignment.
 *
 * @return the result of the expression using
 */
double Plus::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}
