#include "CommandMap.h"

void CommandMap::addCommand(string key, Command *command) {
    this->commandMAp.insert(pair<string,Command*>(key,command));
}
map<string, Command*> CommandMap::getCommandMap(){
    return this->commandMAp;
}

Command* CommandMap::getCommand(string key) {
   if(this->commandMAp.count(key)){
       return this->commandMAp.find(key)->second;
   } else{
       throw "Invalid key";
   }
}

bool CommandMap::isInMap(string key) {
    return this->commandMAp.count(key);
}