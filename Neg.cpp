
#include "Neg.h"

Neg::Neg(Expression *negNum) {
    this->negativeNumber = negNum;
}

double Neg::calculate(map<string, double> &assignment) {
    return (-1)*this->negativeNumber->calculate(assignment);
}

double Neg::calculate() {
    map<string, double> temp;
    calculate(temp);
}