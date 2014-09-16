/*-----------------------------------------------------------------------------
  file productfactory.h
  Factory class that outputs a certain type of Product object
    depending on multiple character inputs.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Implemented using a multi dimensional array for the hash table
         to match the ProductContainer
  Assumptions:
    -- Product hash by default (0) will be movies
-----------------------------------------------------------------------------*/
 
#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H
#include "classic.h"
#include "drama.h"
#include "comedy.h"
 
 
const int MAX_PRODUCTS = 26;
 
class ProductFactory {
private:
    Product* prodFactory[MAX_PRODUCTS]; 
    int hash(char) const;
public:
    ProductFactory();
    ~ProductFactory();
    Product* createIt(char) const;
};
 
#endif
