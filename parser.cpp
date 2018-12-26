#include "parser.h"
#include "SetControlCommand.h"
#include "CommandExpression.h"
#include "SetControlCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"

parser::parser(){
    this->stringControl = new StringFlightControls();
    this->connection = new CheckConnection();
    this->valueMap = new FlightValueMap();
    this->bindMap = new PathMap();
    this->symbols = new SymbolTable(this->valueMap, this->bindMap);
    this->toExit = new ExitServer();
    this->commands=new CommandMap();
    this->commands->addCommand("openDateServer", new OpenServerCommand(this->connection, this->valueMap, this->toExit));
    this->commands->addCommand("connect", new ConnectCommand(this->connection,this->stringControl, this->toExit));
    this->commands->addCommand("var", new VarCommand(this->symbols));
    this->commands->addCommand("control", new SetControlCommand(
            this->stringControl, this->symbols));
    this->commands->addCommand("if", new ConditionParser(this->commands,this->symbols));
    this->commands->addCommand("while", new ConditionParser(this->commands,this->symbols));
    this->commands->addCommand("print", new PrintCommand(this->symbols));
    this->commands->addCommand("sleep", new SleepCommand());
}

void parser::runParser(vector<string> v) {
    vector<string>::iterator vectorIt;
    Expression *commandExpression;
    Command *newCommand;
    for (vectorIt = v.begin(); vectorIt != v.end(); vectorIt++) {
        map<string, double> symbolsMap = this->symbols->getSymbols();
        while (((*vectorIt) != "openDateServer") && (!this->connection->getConnect())){
            sleep(10);
        }
        if (this->symbols->getSymbols().count(*vectorIt)){
            newCommand = this->commands->getCommand("control");
            commandExpression = new CommandExpression(vectorIt, newCommand, this->symbols);
            this->toDelete.push_back(commandExpression);
            vectorIt += commandExpression->calculate(symbolsMap);
        } else if (((*vectorIt) == "if") || ((*vectorIt) == "while")) {
            newCommand = this->commands->getCommand(*vectorIt);
            newCommand->execute(vectorIt);
        } else if (this->commands->isInMap(*vectorIt)) {
            commandExpression = new CommandExpression(vectorIt, this->commands->getCommand(*vectorIt), this->symbols);
            this->toDelete.push_back(commandExpression);
            vectorIt += commandExpression->calculate(symbolsMap);
        }
    }
    this->toExit->setExit(true);
}