#include "PrintCommand.h"

int PrintCommand::execute(vector<string>::iterator &vectorIt) {
    string toPrint = "";
    if((*vectorIt)[0] != '\"'){
        toPrint = (*vectorIt);
    } else {
        while ((*vectorIt) != ";") {
            toPrint += (*vectorIt);
            vectorIt++;
        }
        toPrint = toPrint.substr(1, (toPrint.length()) - 2);
    }
    vectorIt++;

    cout << toPrint << endl;
    return 0;
}