#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"

/**
 * constructor
 */
ConditionParser::ConditionParser(CommandMap* commandMap, SymbolTable *symbolMap) {
    this->symbolTable = symbolMap;
    this->commandMap = commandMap;
}
/**
 * parser the condition
 * @param script iterator
 * @return 0 when finish
 */
int ConditionParser::execute(vector<string>::iterator &vectorIt) {
    //what kind is the condition, get the string value from the iterator
    string whatLoop=(*vectorIt);
    string condition = "";

    Command *newCommand;
    vectorIt++;
    //until the end of the condition
    while ((*vectorIt) != "{") {
        //get the condition
        condition += (*vectorIt);
        vectorIt++;
    }
    //make a condition type from the string of the condition
    this->boolExpression = new BoolExpression(condition, this->symbolTable);
    vectorIt++;
    this->createCommand(vectorIt);
    //if the type of the condition is "while"
    if (whatLoop == "while") {
        //create new LoopCommand
        newCommand = new LoopCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
        //if the type of the condition is "if"
    } else if (whatLoop == "if") {
        //create new ifCommand
        newCommand = new IfCommand(this->boolExpression, this->expressionCommandList, this->symbolTable);
    }
    //execute the command
    newCommand->execute(vectorIt);
    return 0;
}

/**
 * create new command
 * @param vectorIt the iterator
 */
void ConditionParser::createCommand(vector<string>::iterator &vectorIt) {
    Command *newCommand;
    Expression *newExpression;
    CommandExpression* commandExp = NULL;

    //until the end
    while ((*vectorIt) != "}") {
        //get the symbol table
        SymbolTable* symbolsMap = this->symbolTable;
        //if the command is in the map
        if (this->symbolTable->isInSymbol(*vectorIt)) {
            Command *newCommand = this->commandMap->getCommand("control");
            commandExp = new CommandExpression(vectorIt, newCommand, this->symbolTable);
            //add the new command to the list
            this->expressionCommandList.push_back(commandExp);
        } else if (this->commandMap->isInMap(*vectorIt)) {
            //new command expression
            commandExp = new CommandExpression(vectorIt,
                    this->commandMap->getCommand(*vectorIt), this->symbolTable);
            //add to the list
            this->expressionCommandList.push_back(commandExp);
        }
        //until the end
        while ((*vectorIt) != ";"){
            vectorIt++;
        }
        //move the iterator +1
        vectorIt++;
    }
}
