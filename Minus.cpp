
#include "Minus.h"

double Minus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    return leftValue-rightValue;
}
double Minus::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}