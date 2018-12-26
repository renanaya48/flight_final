#include <map>
#include <string>

using namespace std;

#ifndef PROJECT1_EXPRESSION_H
#define PROJECT1_EXPRESSION_H

class Expression {
    /**
     * @param assignment evaluate the expression using in this assignment
     * @return the result of the expression using
     * @throws Exception if the expression contains a variable which is not in the assignment, an exception is thrown.
     */
public:
    virtual double calculate(map<string, double> &assignment) = 0;

    /**
     * A convenience method ,evaluate(assignment)`same to the evaluate method above,
     * but this methods use in empty assignment.
     *
     * @return the result of the expression using
     * @throws Exception if the expression contains a variable which is not in the assignment, an exception is thrown.
     */
    virtual double calculate() = 0;
};

#endif //PROJECT1_EXPRESSION_H
