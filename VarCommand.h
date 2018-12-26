
#ifndef PROJECT1_VARCOMMAND_H
#define PROJECT1_VARCOMMAND_H

#include <map>
#include <string>
#include <vector>
#include "SymbolTable.h"
#include "Command.h"

using namespace std;

class VarCommand: public Command{
    SymbolTable* symbols;
public:
    VarCommand(SymbolTable* s){
        this->symbols = s;
    }
    virtual int execute(vector<string>::iterator &vectorIt);
};


#endif //PROJECT1_VARCOMMAND_H
