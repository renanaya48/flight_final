
#include "Num.h"

/**
 * The function return the value of the operation function.
 *
 * @param assignment evaluate the expression using in this assignment
 * @return value of this num
 * @throws Exception if is not assignment or not valid operation or number
 */
double Num::calculate(map<string, double> &assignment)
{
    return this->num;
}
   /**
 * A convenience method. Like the `evaluate(assignment)` method above, but uses an empty assignment.
 *
 * @return the value of this num
 */
double Num::calculate()
{
    return this->num;
}
