#include "SetControlCommand.h"

int SetControlCommand::execute(vector<string>::iterator &vectorIt){
    string var = *vectorIt;
    vectorIt++;
    string value = *vectorIt;
    string finalString = "set ";
    finalString += this->symbols->getPath(var).substr(1);
    finalString += " ";
    finalString += value;
    finalString += "\r\n";
    this->symbols->setSymbol(var, atof(value.c_str()));
    this->stringControl->setControl(finalString);
    return 0;
}