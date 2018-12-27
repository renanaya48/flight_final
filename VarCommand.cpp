#include "VarCommand.h"

/**
 * execute
 * @param vectorIt the vector
 * @return 0 when done
 */
int VarCommand::execute(vector<string>::iterator &vectorIt){
    int countSteps=0;
    string varName = (*vectorIt);
    vectorIt += 2;
    countSteps+=2;
    if ((*vectorIt) == "bind") {
        vectorIt++;
        countSteps++;
        string temp = (*vectorIt);
        temp = temp.substr(1, (temp.length()) -2);
        this->symbols->addPairSymbol(varName, temp);
    } else {  // not bind
        double num = this->symbols->getValue((*vectorIt));
        this->symbols->addSymbol(varName, num);
    }
    vectorIt++;
    countSteps++;
    return countSteps;
}
