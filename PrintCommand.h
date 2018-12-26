
#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include <map>
#include <iostream>
/**
 * PrintCommand class inheritors Command
 */
class PrintCommand: public Command{
    //member
    SymbolTable* symbolTable;
public:
    /**
     * constructor
     * @param s SymbolTable
     */
    PrintCommand(SymbolTable *s) {
        this->symbolTable = s;
    }
/**
 * 
 * @param vectorIt the iterator
 * @return 0 when done
 */
    virtual int execute(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_PRINTCOMMAND_H
