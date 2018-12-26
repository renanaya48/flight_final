
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
/**
*lexer class
*/
class lexer {
    //member
    string fileName;

public:
      /**
     * constructor
     * @param name the name of the file to read from
     */
    lexer(string name);
     /**
     * the function gets a file and read every word.
     * each word will be in a differend place.
     * @return a vector which every word is in a different place.
     */
    vector<string> lexerFile();
    /**
    * distructor
    */
    ~lexer(){}
};


#endif //PROJECT1_LEXER_H
