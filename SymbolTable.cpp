#include "SymbolTable.h"


void SymbolTable::addPairSymbol(string key, string value) {
    this->bindMap->addToPathMap(key, value);
    if (this->flightValues->getFlightVauleMap().count(value)) {
        this->symbols.insert(pair<string, double>(key, this->flightValues->getFlightVauleMap()
        .find(value)->second));
        this->bindMap->addToPathMap(key, value);
    } else if(this->symbols.count(value)) {
        double tempValue = this->getValue(value);
        this->symbols.insert(pair<string, double>(key,tempValue));
        this->bindedSymbols.insert(pair<string, string>(key, value));
        this->bindedSymbols.insert(pair<string, string>(value, key));
    } else {
        this->symbols.insert(pair<string, double>(key, 0));
        this->bindMap->addToPathMap(key, value);
    }
}

string SymbolTable::getPath(string key){
    if (bindMap->getBindMap().count(key)){
        return bindMap->getBindMap().find(key)->second;
    } else if (this->bindedSymbols.count(key)){
        return bindMap->getBindMap().find(this->bindedSymbols.find(key)->second)->second;
    } else {
        throw ("Path not found\n");
    }
}

void SymbolTable::setSymbol(string key, double num){
    if(this->bindedSymbols.count(key)){
        string tempBind = this->bindedSymbols.find(key)->second;
        symbols.find(key)->second = num;
        symbols.find(tempBind)->second = num;
    } else if (this->bindMap->getBindMap().count(key)){
        symbols.find(key)->second = num;
    }
}

void SymbolTable::addSymbol(string s, double num){
    symbols.insert(std::pair<string, double>(s, num));
}


map<string, double> SymbolTable::getSymbols(){
    return this->symbols;
}

bool SymbolTable::isInSymbol(string str){
    return this->symbols.count(str);
}

double SymbolTable::getValue(string s){
    if(this->symbols.count(s)){
        if(this->bindMap->getBindMap().count(s)){
            if(this->flightValues->getFlightVauleMap().count(this->bindMap->getBindMap().find(s)->second)){
                double temp = this->flightValues->getFlightVauleMap().
                        find(this->bindMap->getBindMap().find(s)->second)->second;
                this->setSymbol(s, temp);
            }
        }
    } else {
        throw ("Symbol not found.\n");
    }
    return this->symbols.find(s)->second;
}

/*void SymbolTable::setBindedSymbols(string s1, string s2){
    this->bindedSymbols.insert(std::pair<string, string>(s1, s2));
    addSymbol(s1, getValue(s2));
}
map<string, string> SymbolTable::getBindedSymbols(){
    return this->bindedSymbols;
}*/