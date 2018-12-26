#include <iostream>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "Expression.h"
#include "CreateExpression.h"
#include <iostream>
#include <fstream>
#include <list>
#include "lexer.h"
#include "parser.h"


int main(int argc, char* argv[]) {
    if(argc != 2){
        throw ("Invalid input");
    }
    string fileName = argv[1];
    lexer* lex = new lexer(fileName);
    vector<string> toParser;
    toParser = lex->lexerFile();
    parser* par = new parser();
    par->runParser(toParser);

    delete lex;
    delete par;
    return 0;
}