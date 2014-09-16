/*-----------------------------------------------------------------------------
  file commandcontainer.h
  Class CommandContainer
  A class that contains all the new Command objects created.
 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Stores all the command objects created
    -- Appends command objects
    -- Deletes the memory allocated by all the new command objects
-----------------------------------------------------------------------------*/
#ifndef COMMAND_CONTAINER_H
#define COMMAND_CONTAINER_H
 
#include "command.h"
#include <list>
 
using namespace std;
 
class CommandContainer {
private:
    // list of Command objects
    list<Command*> commandHistory;
     
public:
    CommandContainer();     // Constructor  
    ~CommandContainer();    // Destructor   
    void appendCommand(Command&);   // Appends commands to commandHistory
};
 
#endif
