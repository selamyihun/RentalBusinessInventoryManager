#include "commandfactory.h"
 
//----------------------------Constructor--------------------------------------
// creates the prototype Command objects and sets the rest of the hash table
// array to NULL
CommandFactory::CommandFactory() {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        commandTypes[i] = NULL;
    }
    commandTypes[1] = new BorrowCommand();
    commandTypes[7] = new DisplayHistory();
    commandTypes[17] = new ReturnCommand();
    commandTypes[18] = new DisplayCategories();
 
}
 
//----------------------------Destructor---------------------------------------
CommandFactory::~CommandFactory() {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if(commandTypes[i] != NULL) {
            delete commandTypes[i];
            commandTypes[i] = NULL;
        }
    }
}
 
//----------------------------createIt-----------------------------------------
// Creates a new Command object based on the char returned by the
// hash function; B = BorrowCommand, R = ReturnCommand, H = DisplayHistory,
// S = DisplayCategories.
Command* CommandFactory::createIt(char ch) const {
    int subscript = hash(ch);             // would do error checking
    if(commandTypes[subscript] == NULL) {
        return NULL;
    }
    return commandTypes[subscript]->create();
}
 
//----------------------------hash-----------------------------------------
int CommandFactory::hash(char ch) const { return ch-'A'; }
