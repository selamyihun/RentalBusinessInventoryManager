/*-----------------------------------------------------------------------------
  file commandfactory.h
  Class CommandFactory
  A factory class that creates new Command objects after hashing a given
  character to a hash table of prototype commands.
 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Creates new Command objects
    -- Creates prototype command objects to duplicate
 
  Assumptions:
    -- The maximum amount of commands possible is currently 26
-----------------------------------------------------------------------------*/
#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
 
#include "borrowcommand.h"
#include "returncommand.h"
#include "displayhistory.h"
#include "displaycategories.h"
const int MAX_COMMANDS = 26;
 
class CommandFactory {
private:
    // hash table for holding protoype Command objects
    Command* commandTypes[MAX_COMMANDS]; 
    // hashing function to hash a character to an array subscript
    int hash(char) const;
 
public:
    CommandFactory();   // Constructor
    ~CommandFactory();  // Destructor
    // Creates a new Command object after hashing the given character
    Command* createIt(char) const;  
};
 
#endif
