#ifndef PROJECT1_STRINGFLIGHTCONTROLS_H
#define PROJECT1_STRINGFLIGHTCONTROLS_H

#include <string>
#include <list>

using namespace std;

class StringFlightControls {
    list<string>controlCommand;
public:
    StringFlightControls(){}

    void setControl(string s){
        this->controlCommand.push_back(s);
    }

    string getControl(){
        string control = this->controlCommand.front();
        this->controlCommand.pop_front();
        return control;
    }

    bool isEmpty(){
        return this->controlCommand.empty();
    }

};


#endif //PROJECT1_STRINGFLIGHTCONTROLS_H
