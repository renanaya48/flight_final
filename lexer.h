
#ifndef PROJECT1_LEXER_H
#define PROJECT1_LEXER_H

#include <iostream>
#include <fstream>
#include "Command.h"
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include <vector>

using namespace std;
class lexer {
    string fileName;

public:
    lexer(string name);
    vector<string> lexerFile();
    ~lexer(){}
};


#endif //PROJECT1_LEXER_H
