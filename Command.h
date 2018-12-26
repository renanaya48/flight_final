#include <string>
#include <vector>

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <map>
#include <mutex>

using namespace std;

/**
 * Command class.
 */
class Command {
public:
    //member
    map<string, double> symbolTable;
public:
    /**
     * constructor
     */
    Command(){}
    /**
     *
     * @param vectorIt the iterator that point to the
     *                  place at the vector
     * @return o if succeed
     */
    virtual int execute(vector<string>::iterator &vectorIt) = 0;
    /**
    * distructor
    */
    ~Command(){}
};

#endif //PROJECT1_COMMAND_H
