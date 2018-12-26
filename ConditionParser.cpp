#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"

ConditionParser::ConditionParser(CommandMap* commandMap, SymbolTable *symbolMap) {
    this->symbolTable = symbolMap;
    this->commandMap = commandMap;
}

int ConditionParser::execute(vector<string>::iterator &vectorIt) {
    string whatLoop=(*vectorIt);
    string condition = "";

    Command *newCommand;
    vectorIt++;

    while ((*vectorIt) != "{") {
        condition += (*vectorIt);
        vectorIt++;
    }
    this->boolExpression = new BoolExpression(condition, this->symbolTable);
    vectorIt++;
    this->createCommand(vectorIt);

    if (whatLoop == "while") {
        newCommand = new LoopCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    } else if (whatLoop == "if") {
        newCommand = new IfCommand(this->boolExpression, this->expressionCommandList, this->symbolTable);
    }
    newCommand->execute(vectorIt);
    return 0;
}

void ConditionParser::createCommand(vector<string>::iterator &vectorIt) {
    Command *newCommand;
    Expression *newExpression;
    CommandExpression* commandExp = NULL;

    while ((*vectorIt) != "}") {
        SymbolTable* symbolsMap = this->symbolTable;
        if (this->symbolTable->isInSymbol(*vectorIt)) {
            Command *newCommand = this->commandMap->getCommand("control");
            commandExp = new CommandExpression(vectorIt, newCommand, this->symbolTable);
            this->expressionCommandList.push_back(commandExp);
        } else if (this->commandMap->isInMap(*vectorIt)) {
            commandExp = new CommandExpression(vectorIt,
                    this->commandMap->getCommand(*vectorIt), this->symbolTable);
            this->expressionCommandList.push_back(commandExp);
        }
        while ((*vectorIt) != ";"){
            vectorIt++;
        }
        vectorIt++;
    }
}
