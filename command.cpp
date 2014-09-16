#include "command.h"
 
//----------------------------Constructor--------------------------------------
// Initializes the productContainer, customerContainer, customer, and product 
// to NULL. Initializes name to an empty string
Command::Command(){
    productContainer = NULL;
    customerContainer = NULL;
    customer = NULL;
    product = NULL;
    name = "";
}
 
//----------------------------Destructor---------------------------------------
Command::~Command() { }
 
//-----------------------------------------------------------------------------
// getName()
// Gets the name of the command
string Command::getName() const {
    return name;
}
 
//-----------------------------------------------------------------------------
// getProduct()
//  Returns the pointer to the product associated with the command
Product* Command::getProduct() const {
    return product;
}
