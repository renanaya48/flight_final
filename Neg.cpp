
#include "Neg.h"
/**
 * constructor
 * @param negativeNumber Expression
 */
Neg::Neg(Expression *negNum) {
    this->negativeNumber = negNum;
}
/**
 * calculate the neg of the number
 * @param assignment map
 * @return the neg number
 */
double Neg::calculate(map<string, double> &assignment) {
    //mult by (-1)
    return (-1)*this->negativeNumber->calculate(assignment);
}
/**
 *
 * @return the neg number
 */
double Neg::calculate() {
    map<string, double> temp;
    calculate(temp);
}
