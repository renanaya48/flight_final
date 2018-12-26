#include "CommandExpression.h"

double CommandExpression::calculate(map<string, double> &assignment) {
    string expression;
    int resultExpression;

    vector<string> newVector;
    Expression *newExpression;
    vector<string>::iterator tempItr;
    tempItr=this->vectorIt;

    CreateExpression *createExpression = new CreateExpression(this->symbols);

    int counter = 0;

    if ((*vectorIt)=="var") {
        vectorIt++;
        counter++;
        counter += this->command->execute(vectorIt);
    } else if (((*this->vectorIt) == "openDateServer") || ((*this->vectorIt) == "sleep")) {
        this->vectorIt++;
        counter++;
        while ((*this->vectorIt) != ";") {
            expression = (*vectorIt);
            newExpression = createExpression->convertToExpression(expression);
            resultExpression = (int) newExpression->calculate(assignment);
            newVector.push_back(to_string(resultExpression));
            vectorIt++;
            counter++;
        }
        vector<string>::iterator itr;

        itr=newVector.begin();
        this->command->execute(itr);

    } else if((*vectorIt) == "connect"){
        vectorIt++;
        counter++;

        string ip = (*vectorIt);
        newVector.push_back(ip);
        vectorIt++;
        counter++;

        expression = (*vectorIt);
        newExpression = createExpression->convertToExpression(expression);
        resultExpression = (int) newExpression->calculate(assignment);
        newVector.push_back(to_string(resultExpression));

        vector<string>::iterator tempIt;
        tempIt = newVector.begin();

        this->command->execute(tempIt);

    } else if((*vectorIt) == "print"){
        vectorIt++;
        counter++;

        if((*vectorIt)[0]=='\"'){
            this->command->execute(vectorIt);
        } else {
            while ((*this->vectorIt) != ";") {
                expression = (*vectorIt);
                newExpression = createExpression->convertToExpression(expression);
                resultExpression = (int) newExpression->calculate(assignment);
                newVector.push_back(to_string(resultExpression));
                vectorIt++;
                counter++;
            }
            vector<string>::iterator itr;
            itr=newVector.begin();
            this->command->execute(itr);
        }
    } else {
        newVector.push_back(*this->vectorIt);
        string expressin = "";

        this->vectorIt += 2;
        counter += 2;
        while ((*this->vectorIt) != ";") {
            expressin += (*this->vectorIt);
            this->vectorIt++;
            counter++;
        }
        newExpression = createExpression->convertToExpression(expressin);
        double result = newExpression->calculate(assignment);
        newVector.push_back(to_string(result));
        vector<string>::iterator newVectorIt;
        newVectorIt = newVector.begin();
        this->command->execute(newVectorIt);
    }
    this->vectorIt=tempItr;
    delete createExpression;
    return counter;
}

double CommandExpression::calculate() {
    map<string, double> temp;
    calculate(temp);
}
