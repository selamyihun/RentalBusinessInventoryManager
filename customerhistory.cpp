#include "customerhistory.h"
#include "command.h" 
 
//----------------------------Constructor--------------------------------------
CustomerHistory::CustomerHistory() { }
 
//----------------------------Destructor---------------------------------------
CustomerHistory::~CustomerHistory() { }
 
//-----------------------------------------------------------------------------
// appendCommand()
// Appends command to commandHistory
void CustomerHistory::appendCommand(Command& command) {
    commandHistory.push_back(&command);
}
 
//-----------------------------------------------------------------------------
// printHistory()
// Prints the customer's history
void CustomerHistory::printHistory() const {
    list<Command*>::const_iterator ptr = commandHistory.begin();
    for (ptr; ptr != commandHistory.end(); ++ptr){
        (*ptr)->printData();
    }   
}
 
//-----------------------------------------------------------------------------
// getCommandHistory()
// Retrieves history, not const because we access the address of 
// commandHistory
list<Command*>* CustomerHistory::getCommandHistory() {
    return &commandHistory;
}
