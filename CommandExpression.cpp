#include "CommandExpression.h"

/**
 *
 * @param assignment map
 * @return the result of the expression in numbers
 */
double CommandExpression::calculate(map<string, double> &assignment) {
    string expression;
    int resultExpression;

    vector<string> newVector;
    Expression *newExpression;
    vector<string>::iterator tempItr;
    tempItr=this->vectorIt;

    CreateExpression *createExpression = new CreateExpression(this->symbols);

    int counter = 0;
    
    //if the current string in the vector is "var"
    if ((*vectorIt)=="var") {
        //move the iterator 1 step
         vectorIt++;
        //count 1 step
        counter++;
        counter += this->command->execute(vectorIt);
        //if the value is "openDateServer" or "sleep"
    } else if (((*this->vectorIt) == "openDateServer") || ((*this->vectorIt) == "sleep")) {
        //move the iterator 1 step
        this->vectorIt++;
        //count 1 step
        counter++;
         //move until the end
        while ((*this->vectorIt) != ";") {
            //put the string value of the expression in expression
            expression = (*vectorIt);
            //make the string to expression
            newExpression = createExpression->convertToExpression(expression);
            //calculate the result of the expression
            resultExpression = (int) newExpression->calculate(assignment);
            //add the result of the expression to the new vector
            newVector.push_back(to_string(resultExpression));
            //move the iterator 1 step
            vectorIt++;
            //count 1 step
            counter++;
        }
        //iterator to the new vector
        vector<string>::iterator itr;

        itr=newVector.begin();
        //execute the command
        this->command->execute(itr);

     //if the value in the vector is "connect"
    } else if((*vectorIt) == "connect"){
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        counter++;
        //put the string value of the ip in ip and add it to the new vector
        string ip = (*vectorIt);
        //put the ip in the new vector
        newVector.push_back(ip);
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        counter++;
        //put the string value of the expression in expression
        expression = (*vectorIt);
        //make the string to expression
        newExpression = createExpression->convertToExpression(expression);
        //calculate the result of the expression
        resultExpression = (int) newExpression->calculate(assignment);
        //add the result of the expression to the new vector
        newVector.push_back(to_string(resultExpression));
        //iterator to the new vector
        vector<string>::iterator tempIt;
        tempIt = newVector.begin();
        //execute the command
        this->command->execute(tempIt);

    //if the string value of the iterator is "print"    
    } else if((*vectorIt) == "print"){
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        counter++;

        if((*vectorIt)[0]=='\"'){
            //execute the command
            this->command->execute(vectorIt);
        } else {
            //until the end
            while ((*this->vectorIt) != ";") {
                //put the string value of the expression in expression
                expression = (*vectorIt);
                //make the string to expression
                newExpression = createExpression->convertToExpression(expression);
                //calculate the result of the expression
                resultExpression = (int) newExpression->calculate(assignment);
                //add the result of the expression to the new vector
                newVector.push_back(to_string(resultExpression));
                //move the iterator 1 step
                vectorIt++;
                //count 1 step
                counter++;
            }
            //iterator to the new vector
            vector<string>::iterator itr;
            itr=newVector.begin();
            //execute the command
            this->command->execute(itr);
        }
    } else {
        //add the string value to the new vector
        newVector.push_back(*this->vectorIt);
        string expressin = "";
        //add 2 to the vector and to the steps
        this->vectorIt += 2;
        counter += 2;
        //until the end
        while ((*this->vectorIt) != ";") {
            expressin += (*this->vectorIt);
            //add 1 to the iterator and to the counter
            this->vectorIt++;
            counter++;
        }
        //make the string to expression
        newExpression = createExpression->convertToExpression(expressin);
        //calculate the result of the expression
        double result = newExpression->calculate(assignment);
        //add the result of the expression to the new vector
        newVector.push_back(to_string(result));
        //iterator to the new vector
        vector<string>::iterator newVectorIt;
        newVectorIt = newVector.begin();
        //execute the command
        this->command->execute(newVectorIt);
    }
    this->vectorIt=tempItr;
    delete createExpression;
    //return the counter
    return counter;
}
/**
 * calculate the value of the expression
 * @return the value after calculate
 */
double CommandExpression::calculate() {
    map<string, double> temp;
    calculate(temp);
}
