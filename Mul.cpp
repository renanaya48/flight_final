
#include "Mul.h"
/**
 * calculate the value of the mul
 * @param assignment
 * @return the value of calculate
 */
double Mul::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    //get the values of the right and left expressions
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    //calculate and return mult
    return leftValue * rightValue;
    throw invalid_argument("");
}
/**
 * A convenience method ,evaluate(assignment)`same to the evaluate method above,
 * but this methods use in empty assignment.
 *
 * @return the result of the expression using
 */
double Mul::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}
