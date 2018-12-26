#ifndef PROJECT1_SLEEPCOMMMAND_H
#define PROJECT1_SLEEPCOMMMAND_H

#include "Command.h"

class SleepCommand: public Command {
public:
    virtual int execute(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_SLEEPCOMMMAND_H
