/*-----------------------------------------------------------------------------
  file storemanager.h
  Authors: Selam Yihun & Jacob Jelovich
   
  StoreManager class:  a class that manages all the processes and data related
                         to handling products offered by the store. The class
    -- allows the input of customer data
    -- allows the partial input of customer commands
    -- allows the partial input of product data  
    -- allows the output of customer history
    -- allows the output of the store's products
    -- holds the customer and product data
 
  Implementation and Assumptions:  
    -- the data must be formatted correctly
    -- if a new product needs to be added the input data shall change,
         therefore, the productfactory needs to be modified    
    -- the products will be contained in a hash table, and the
         product types will be contained in a hash table, the final
         concrete class product will be contained in a binary search tree
-----------------------------------------------------------------------------*/
 
#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H
 
#include "productcontainer.h"
#include "productfactory.h"
#include "customertable.h"
#include "commandfactory.h"
#include "commandcontainer.h"
#include <iostream>
 
const int MAX_LINE = 256; // the maximum chars in a line, used for getline
 
using namespace std;
 
class StoreManager {
public:
    // builds the respective BinTrees of pruducts from the 
    // provided movie data file
    bool buildTree(ProductContainer&);
    // builds a table of customers from the provided customer data file
    bool buildCustomerTable(CustomerTable&);
    // runs commands according to input form the provided command data file
    void runCommands(CustomerTable&, ProductContainer&);
};
 
#endif
