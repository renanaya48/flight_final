#include "lexer.h"

/**
 * constructor
 * @param name the name of the file to read from
 */
lexer::lexer(string name){
    this->fileName = name;
}

/**
 * the function gets a file and read every word.
 * each word will be in a differend place.
 * @return a vector which every word is in a different place.
 */
vector<string> lexer::lexerFile() {
    vector<string> buffer;
    string line;
    ifstream lexFile;
    string temp = "";

    //open the file
    lexFile.open(this->fileName, ios::in);
    //if the open file had been succeed
    if (lexFile.is_open()){
        //go on all the file, each time get a line
        while (getline(lexFile, line)){
            int index = 0;
            //cut the line, after every space, end, tab
            while(line[index] != '\0'){
                if((line[index] != ' ') && (line[index] != '\t')){
                    temp += line[index];
                } else if(temp != "") {
                    //put the word in the vector
                    buffer.push_back(temp);
                    temp = "";
                }
                index++;
            }
            buffer.push_back(temp);
            temp = "";
            //in the end add ";"
            buffer.push_back(";");
        }
        //close file
        lexFile.close();
        //the file dwdnt open
    } else {
        throw "unable to open file";
    }
    //return the vector
    return buffer;
}
