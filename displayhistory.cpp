#include "displayhistory.h"
 
//----------------------------Constructor--------------------------------------
// sets the name of the command to Display History
DisplayHistory::DisplayHistory() : Command() { 
    name = "Display History";
 }
 
//-----------------------------------------------------------------------------
// execute()
// This function prints the customer's transaction history
// This is not const because other derived classes from Command like 
// BorrowCommand and ReturnCommand append themselves to customer's history
void DisplayHistory::execute(ifstream& infile) {
    int id = 0;
    char line[MAX_LINE_2];
 
    infile >> id;
 
    customer = customerContainer->getCustomer(id); 
     
    if(customer == NULL){
        cout << endl << "Customer with ID " << id << " not found!" << endl;
    } else {
        infile.getline(line, MAX_LINE_2);
        customer->printHistory();
    }
}
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of DisplayHistory object
Command* DisplayHistory::create() const {
    return new DisplayHistory();
}
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active CustomerTable pointer to the command
void DisplayHistory::setData(ProductContainer* container,
                             CustomerTable* customers) {
    customerContainer = customers;
}
 
//-----------------------------------------------------------------------------
// printData()
// Doesn't do anything for this class. Used in other classes derived from
// the command class
void DisplayHistory::printData() const { }
