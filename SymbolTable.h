#ifndef PROJECT1_SYMBOLTABLE_H
#define PROJECT1_SYMBOLTABLE_H

#include <map>
#include <string>
#include "FlightValueMap.h"
#include "PathMap.h"

using namespace std;

class SymbolTable{
    map<string, double> symbols;
    map<string, string> bindedSymbols;
    FlightValueMap* flightValues;
    PathMap* bindMap;

public:
    SymbolTable(FlightValueMap* flightVal, PathMap* bind){
        this->flightValues = flightVal;
        this->bindMap = bind;
    }
    void setSymbol(string s, double num);
    void addSymbol(string s, double num);
    map<string, double> getSymbols();
    double getValue(string s);
    bool isInSymbol(string str);
    //void setBindedSymbols(string s1, string s2);
    //map<string, string> getBindedSymbols();
    void addPairSymbol(string key, string value) ;
    string getPath(string key);

};

#endif //PROJECT1_SYMBOLTABLE_H
