#include "commandcontainer.h"
 
//----------------------------Constructor--------------------------------------
CommandContainer::CommandContainer() { }
 
//----------------------------Destructor---------------------------------------
CommandContainer::~CommandContainer() { 
    list<Command*>::iterator ptr = commandHistory.begin();
    for (ptr; ptr != commandHistory.end(); ++ptr){
        delete (*ptr);
        (*ptr) = NULL;
    }   
}
 
//-----------------------------------------------------------------------------
// appendCommand()
// Appends the given command to commandHistory, which is a list of commands
void CommandContainer::appendCommand(Command& command) {
    commandHistory.push_back(&command);
}
