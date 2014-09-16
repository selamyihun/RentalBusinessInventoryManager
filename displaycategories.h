/*-----------------------------------------------------------------------------
  file displaycategories.h
  Class DisplayCategories
  A concrete class derived form the Command class. This class is responsible
  for performing displaying the stores products their stock. 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Creates a new DisplayCategories object
    -- Prints the products in the store and their stock
    -- Sets the active ProductContainer and CustomerTable pointers to the
        Command
 
  Assumptions:
    -- Input files are correctly formatted for performing transaction
-----------------------------------------------------------------------------*/
#ifndef DISPLAY_CATEGORIES_H
#define DISPLAY_CATEGORIES_H
 
#include "command.h"
 
 
class DisplayCategories : public Command {
public:
    DisplayCategories();    // Constructor
 
//-----------------------------------------------------------------------------
// execute()
// Prints the products in the store and their stock
// This is not const because other derived classes from Command like 
// BorrowCommand and ReturnCommand append themselves to customer's history
    virtual void execute(ifstream&);
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of DisplayHistory object
    virtual Command* create() const;
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active ProductContainer and CustomerTable pointers to the command
    virtual void setData(ProductContainer*, CustomerTable*);
 
//-----------------------------------------------------------------------------
// printData()
// Doesn't do anything for this class. Used in other classes derived from
// the command class
    virtual void printData() const;
};
 
#endif
