#include "SetControlCommand.h"

/**
 * execute
 * @param vectorIt the iterator
 * @return o when done
 */
int SetControlCommand::execute(vector<string>::iterator &vectorIt){
    //put the value in var
    string var = *vectorIt;
    vectorIt++;
    string value = *vectorIt;
    //set the values
    string finalString = "set ";
    finalString += this->symbols->getPath(var).substr(1);
    finalString += " ";
    finalString += value;
    finalString += "\r\n";
    this->symbols->setSymbol(var, atof(value.c_str()));
    this->stringControl->setControl(finalString);
    return 0;
}
