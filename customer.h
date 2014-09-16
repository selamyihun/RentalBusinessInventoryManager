/*-----------------------------------------------------------------------------
  file customer.h
  Class Customer
  A Customer class that holds all the data and operations related to the 
  store's customer.
 
  Authors: Selam Yihun & Jacob Jelovich 
 
  Implementation:
    -- Sets the customer data (id, first name, last name) from a file
    -- Appends a given command to the customer's history
    -- Prints the customer's transaction history
    -- Gets the customer's transaction history
-----------------------------------------------------------------------------*/
#ifndef CUSTOMER_H
#define CUSTOMER_H
 
#include <iostream>
#include <fstream>
#include <string>
#include "customerhistory.h" 
 
using namespace std;
 
class Customer {
 
private:
    // customer ID
    int id;
    // First and Last Names of the customer
    string lastName, firstName;
 
protected:
    // contains the history of transactions performed by the customer
    CustomerHistory history;
 
public:
    Customer();     // Constructor
    ~Customer();    // Destructor
    void setData(ifstream&, int);   // Sets the customer data from file
    void appendHistory(Command&);   // Appends command to customer history
    void printHistory() const;      // Prints the customer history
    // gets customer histor, not const because we access the address of history
    CustomerHistory* getHistory();
};
 
#endif
