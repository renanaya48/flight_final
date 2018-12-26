//
// Created by Administrator on 11/12/2018.
//

#include "Plus.h"

double Plus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    return leftValue+rightValue;
}
double Plus::calculate() {
    map<string, double> assignment;
    return calculate(assignment);
}