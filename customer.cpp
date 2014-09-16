#include "customer.h"
 
//----------------------------Constructor--------------------------------------
// sets the default id, first name, and last name
Customer::Customer() {
    id = 0;
    lastName = firstName = "";
}
 
//----------------------------Destructor---------------------------------------
Customer::~Customer() { }
 
//-----------------------------------------------------------------------------
// setData()
// Sets the customer data (id, first name, last name) from a file
void Customer::setData(ifstream& infile, int custID) {
    id = custID;
    infile >> lastName >> firstName;    // input lastName & firstName   
}
 
//-----------------------------------------------------------------------------
// appendHistory()
// Appends a given command to the customer's historyt
void Customer::appendHistory(Command& command) {
    history.appendCommand(command);
}
 
 
//-----------------------------------------------------------------------------
// printHistory()
// Prints the customer's transaction history
void Customer::printHistory() const {
    cout << endl << "  " << "*** Customer ID = " << 
        id << "\t" << lastName << ' ' << firstName
        << endl;
        history.printHistory();
}
 
//-----------------------------------------------------------------------------
// getHistory()
// gets customer histor, not const because we access the address of history
CustomerHistory* Customer::getHistory() {
    return &history;
}
