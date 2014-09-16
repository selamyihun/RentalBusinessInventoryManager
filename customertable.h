/*-----------------------------------------------------------------------------
  file customertable.h
  Class CustomerTable
  A class that contains all the new Customer objects created.
 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Stores all the Customer objects created
    -- Adds Customer objects to the customerTable (container)
    -- Retrieves Customer object from the customerTable (container)
 
  Assumptions:
    -- The customerTable size, that is the maximum number of customers is
        set to 10000
-----------------------------------------------------------------------------*/
#ifndef CUSTOMER_TABLE_H
#define CUSTOMER_TABLE_H
 
#include "customer.h"
const int DEFAULT_SIZE = 10000;
 
class CustomerTable {
 
private:
    // array that contains the pointers to Customer objects
    Customer* customerTable[DEFAULT_SIZE];
 
public:
    CustomerTable();    // Constructor
    ~CustomerTable();   // Destructor
    Customer* getCustomer(int) const;   // retrieves customer from container
    void setCustomer(int, Customer*);   // adds customer to the container 
};
 
#endif
