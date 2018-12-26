#include "Div.h"
/**
 * calculate the div expression
 * @param assignment map
 * @return the value after calculate
 */
double Div::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    
    //get the left expression value
    leftValue = this->leftArgument->calculate(assignment);
    //get the right expression value
    rightValue = this->rightArgument->calculate(assignment);

    //can't dived by 0
    if(rightValue != 0) {
        //return the diving
        return leftValue / rightValue;
    }
    throw "ERROR: can't dived by 0";
}
/**
 * A convenience method ,evaluate(assignment)`same to the evaluate method above,
 * but this methods use in empty assignment.
 *
 * @return the result of the expression using
 * @throws Exception if the expression contains a variable which is not in the assignment, an exception is thrown.
 */
double Div::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}
