#ifndef PROJECT1_SETCONTROLCOMMAND_H
#define PROJECT1_SETCONTROLCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "StringFlightControls.h"

class SetControlCommand: public Command {
    StringFlightControls* stringControl;
    SymbolTable* symbols;

public:
    SetControlCommand(StringFlightControls* stringC, SymbolTable* symbol){
        this->symbols = symbol;
        this->stringControl = stringC;
    }

    virtual int execute(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_SETCONTROLCOMMAND_H
