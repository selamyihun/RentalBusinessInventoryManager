/*-----------------------------------------------------------------------------
  file customerhistory.h
  Class CustomerHistory
  A class that contains all the transactions performed by the customer.
 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Appends a given command to the customer's history
    -- Prints the customer's transaction history
    -- Retrieves the customer's transaction history
-----------------------------------------------------------------------------*/
#ifndef CUSTOMER_HISTORY_H
#define CUSTOMER_HISTORY_H
 
#include <list>
 
using namespace std;
 
class Command; 
 
class CustomerHistory {
private:
    // list of the customer's transaction history
    list<Command*> commandHistory;
     
 
public:
    CustomerHistory();      // Constructor
    ~CustomerHistory();     // Destructor
    void appendCommand(Command&);   // appends command to commandHistory
    void printHistory() const;      // prints the customer's history
    // retrieves history, not const we access the address of commandHistory
    list<Command*>* getCommandHistory();
 
};
 
#endif
