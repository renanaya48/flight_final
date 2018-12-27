
#ifndef PROJECT1_VARCOMMAND_H
#define PROJECT1_VARCOMMAND_H

#include <map>
#include <string>
#include <vector>
#include "SymbolTable.h"
#include "Command.h"

using namespace std;

/**
 * VarCommand class inheritors Command
 */
class VarCommand: public Command{
    //member
    SymbolTable* symbols;
public:
     /**
     * constructor
     * @param s  SymbolTable
     */
    VarCommand(SymbolTable* s){
        this->symbols = s;
    }
     /**
     *
     * @param vectorIt the vector
     * @return 0 when done
     */
    virtual int execute(vector<string>::iterator &vectorIt);
};


#endif //PROJECT1_VARCOMMAND_H
