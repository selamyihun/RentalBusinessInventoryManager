/*-----------------------------------------------------------------------------
  file borrowcommand.h
  Class BorrowCommand
  A concrete class derived form the Command class. This class is responsible
  for performing borrowing transaction of a product from the store. 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Creates a new BorrowCommand object
    -- Performs borrow transaction
    -- Sets the active ProductContainer and CustomerTable pointers to the
        Command
    -- Prints the command data to the console
  Assumptions:
    -- Input files are correctly formatted for performing transaction
-----------------------------------------------------------------------------*/
#ifndef BORROW_COMMAND_H
#define BORROW_COMMAND_H
 
 
#include "command.h"
 
class BorrowCommand : public Command {
private:
//-----------------------------------------------------------------------------
// executeHelper()
//  Helper function for execute()
    void executeHelper(ifstream&, int);
 
public:
    BorrowCommand();    // Constructor
 
//-----------------------------------------------------------------------------
// execute()
// This function takes care of the transaction than needs to be performed
// by the command object. 
// This function is not const because it appends this object to the 
// customer's history.
    virtual void execute(ifstream&);
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of BorrowCommand object
    virtual Command* create() const;
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active ProductContainer and CustomerTable pointers to the command
    virtual void setData(ProductContainer*, CustomerTable*);
 
//-----------------------------------------------------------------------------
// printData()
// Prints the command data to the console, it prints the MediaFormat, the
// name of the command and the product the command was performed on
    virtual void printData() const;
};
 
#endif
