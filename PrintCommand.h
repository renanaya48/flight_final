
#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include <map>
#include <iostream>

class PrintCommand: public Command{
    SymbolTable* symbolTable;
public:
    PrintCommand(SymbolTable *s) {
        this->symbolTable = s;
    }

    virtual int execute(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_PRINTCOMMAND_H
