/*-----------------------------------------------------------------------------
  file displayhistory.h
  Class DisplayHistory
  A concrete class derived form the Command class. This class is responsible
  for performing displaying the command history of a given customer.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Creates a new DisplayHistory object
    -- Prints the history of the customer's transactions
    -- Sets the active ProductContainer and CustomerTable pointers to the
        Command
 
  Assumptions:
    -- Input files are correctly formatted for performing transaction
-----------------------------------------------------------------------------*/
 
#ifndef DISPLAY_HISTORY_H
#define DISPLAY_HISTORY_H
 
#include "command.h"
 
class DisplayHistory : public Command {
public:
    DisplayHistory();   // Constructor
 
//-----------------------------------------------------------------------------
// execute()
// This function prints the customer's transaction history
// This is not const because other derived classes from Command like 
// BorrowCommand and ReturnCommand append themselves to customer's history
    virtual void execute(ifstream&);
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of DisplayHistory object
    virtual Command* create() const;
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active CustomerTable pointer to the command
    virtual void setData(ProductContainer*, CustomerTable*);
 
//-----------------------------------------------------------------------------
// printData()
// Doesn't do anything for this class. Used in other classes derived from
// the command class
    virtual void printData() const;
};
 
#endif
