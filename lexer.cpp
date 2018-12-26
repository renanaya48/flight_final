#include "lexer.h"

lexer::lexer(string name){
    this->fileName = name;
}

vector<string> lexer::lexerFile() {
    vector<string> buffer;
    string line;
    ifstream lexFile;
    string temp = "";

    lexFile.open(this->fileName, ios::in);

    if (lexFile.is_open()){
        while (getline(lexFile, line)){
            int index = 0;

            while(line[index] != '\0'){
                if((line[index] != ' ') && (line[index] != '\t')){
                    temp += line[index];
                } else if(temp != "") {
                    buffer.push_back(temp);
                    temp = "";
                }
                index++;
            }
            buffer.push_back(temp);
            temp = "";
            buffer.push_back(";");
        }
        lexFile.close();
    } else {
        throw "Can't open file";
    }

    return buffer;
}
