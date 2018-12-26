#include "BoolExpression.h"

void BoolExpression::createBoolExpression(string conditionToCheck) {

    CreateExpression* createExpression = new CreateExpression(this->symbols);

    string expression = "";
    this->action = "";
    int strLen = 0;

    unsigned long int size = conditionToCheck.size();

    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '!') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '>')) {
        expression += conditionToCheck[strLen];
        strLen++;

        if(strLen == (size - 1)){
            throw ("ERROR - invalid condition");
        }
    }

    this->leftArgument = createExpression->convertToExpression(expression);
    while ((conditionToCheck[strLen] == '<') || (conditionToCheck[strLen] == '>') ||
           (conditionToCheck[strLen] == '=') || (conditionToCheck[strLen] == '!')) {
        action += conditionToCheck[strLen];
        strLen++;
    }
    expression = "";

    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '>') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '!') &&
           (strLen < conditionToCheck.length())) {
        expression += conditionToCheck[strLen];
        strLen++;
    }
    this->rightArgument = createExpression->convertToExpression(expression);
    delete (createExpression);
}

bool BoolExpression::calculateBool(map<string, double> symbolMap) {
    if (this->action == "<") {
        return ((leftArgument->calculate(symbolMap)) <
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">") {
        return ((leftArgument->calculate(symbolMap)) >
                rightArgument->calculate(symbolMap));
    } else if (this->action == "<=") {
        return ((leftArgument->calculate(symbolMap)) <=
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">=") {
        return ((leftArgument->calculate(symbolMap)) >=
                rightArgument->calculate(symbolMap));
    } else if (this->action == "==") {
        return ((leftArgument->calculate(symbolMap)) ==
                rightArgument->calculate(symbolMap));
    } else if (this->action == "!=") {
        return ((leftArgument->calculate(symbolMap)) !=
                rightArgument->calculate(symbolMap));
    } else {
        throw "Invald argument";
    }
}
