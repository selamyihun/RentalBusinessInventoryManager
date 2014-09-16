#include "customertable.h"
 
//----------------------------Constructor--------------------------------------
// Sets all the Customer pointers in the customerTable array to NULL
CustomerTable::CustomerTable() {
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        customerTable[i] = NULL;
    }
}
 
//----------------------------Destructor---------------------------------------
CustomerTable::~CustomerTable() {
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        if(customerTable[i] != NULL) {
            delete customerTable[i];
            customerTable[i] = NULL;
        }
    }
}
 
//-----------------------------------------------------------------------------
// getCustomer()
// Retrieves Customer from the customerTable array
Customer* CustomerTable::getCustomer(int id) const {
    return customerTable[id];
}
 
//-----------------------------------------------------------------------------
// setCustomer()
// adds Customer to the customerTable array
void CustomerTable::setCustomer(int id, Customer* customer) {
    customerTable[id] = customer;
}
