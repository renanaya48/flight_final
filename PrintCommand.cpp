#include "PrintCommand.h"
/**
 *execute
 * @param vectorIt the iterator
 * @return 0 when done
 */
int PrintCommand::execute(vector<string>::iterator &vectorIt) {
    string toPrint = "";
    //there ate chars in the string
    if((*vectorIt)[0] != '\"'){
        //put the value in toPrint
        toPrint = (*vectorIt);
        //no chars
    } else {
        //until the end
        while ((*vectorIt) != ";") {
            //get the word
            toPrint += (*vectorIt);
            vectorIt++;
        }
        toPrint = toPrint.substr(1, (toPrint.length()) - 2);
    }
    vectorIt++;

    //print
    cout << toPrint << endl;
    return 0;
}
