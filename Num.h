//
// Created by Administrator on 10/12/2018.
//
#include <string>
#include "string.h"
#include <unordered_map>
#include <vector>
#include "list"
#include <stdexcept>
#include "Expression.h"
using namespace std;
#ifndef PROJECT1_NUM_H
#define PROJECT1_NUM_H


class Num : public Expression
{
//Members
private:
    double num;

public:
    const string OPERATOR = "Num";


    /**
     * The function build Num by double.
     *
     * @param num a double type
     */
    Num(double n){
        this->num=n;
    }

    /**
     * The function return the value of the operation function.
     *
     * @param assignment evaluate the expression using in this assignment
     * @return value of this num
     * @throws Exception if is not assignment or not valid operation or number
     */
    virtual double calculate(map<string, double> &assignment) ;

    /**
     * A convenience method. Like the `evaluate(assignment)` method above, but uses an empty assignment.
     *
     * @return the value of this num
     * @throws Exception if is not assignment or not valid operation or number
     */
    virtual double calculate() ;


};
#endif //PROJECT1_NUM_H
