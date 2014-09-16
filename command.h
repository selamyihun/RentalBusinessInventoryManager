/*-----------------------------------------------------------------------------
  file command.h
  Class Command
  A class that holds all the data and operation related to performing 
  commands from a customer on a given product. 
 
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Gets the product associated with the command
    -- Gets the name of the command
    -- Performs a command
    -- Creates a new command object
    -- Prints the command data
    -- Sets the productContainer and customerContainer of the command
 
  Assumptions:
    -- The maximum size of a line in an input file is 256
-----------------------------------------------------------------------------*/
#ifndef COMMAND_H
#define COMMAND_H
 
#include "product.h"
#include "productcontainer.h"
#include "customertable.h"
#include "productfactory.h"
#include <fstream>
#include <string>
 
const int MAX_LINE_2 = 256;
 
using namespace std;
 
class Command {
protected:
    // pointer to the container of Products
    ProductContainer* productContainer;
    // pointer to the container of Customers
    CustomerTable* customerContainer;
    // pointer to the cutomer performing command
    Customer* customer;
    // pointer to the product on which command will be performed on
    Product* product;
    // the name of the command
    string name;
 
public:
    Command();      // Constructor
    ~Command();     // Destructor
    // pure virtual function for executing a command
    virtual void execute(ifstream&) = 0;
    // pure virtual function for creating a new command object
    virtual Command* create() const = 0;
    // pure virtual function for setting the product and customer containers
    virtual void setData(ProductContainer*, CustomerTable*) = 0;
    // pure virtual function for printing command data
    virtual void printData() const = 0; 
    string getName() const;     // gets the name of the command
    Product* getProduct() const;    // gets the product
 
};
 
#endif
