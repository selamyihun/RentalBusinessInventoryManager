#include "displaycategories.h"
 
//----------------------------Constructor--------------------------------------
// sets the name of the command to Display History
DisplayCategories::DisplayCategories() : Command() {  
    name = "Display Categories";
}
 
//-----------------------------------------------------------------------------
// execute()
// Prints the products in the store and their stock
// This is not const because other derived classes from Command like 
// BorrowCommand and ReturnCommand append themselves to customer's history
void DisplayCategories::execute(ifstream& infile) {
    cout << endl;
    productContainer->printTree('C');
    cout << endl;
    productContainer->printTree('F');
    cout << endl;
    productContainer->printTree('D');
    cout << endl;
}
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of DisplayHistory object
Command* DisplayCategories::create() const {
    return new DisplayCategories();
}
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active ProductContainer and CustomerTable pointers to the command
void DisplayCategories::setData(ProductContainer* container,
                                CustomerTable* customers) {
    productContainer = container;
    customerContainer = customers;
}
 
//-----------------------------------------------------------------------------
// printData()
// Doesn't do anything for this class. Used in other classes derived from
// the command class
void DisplayCategories::printData() const { }
