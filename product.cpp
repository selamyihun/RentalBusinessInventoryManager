#include "product.h"
 
//----------------------------Constructor--------------------------------------
// sets productType, category, totalStock, and currentStock to their 
// default values
Product::Product() {
    productType = "";
    category = '\0';
    totalStock = 0;
    currentStock = 0;
}
 
//----------------------------Destructor---------------------------------------
Product::~Product() { }
 
//----------------------------getCategory--------------------------------------
// returns the category of the product(movie)
char Product::getCategory() const {
    return category;
}
 
//------------------------getCurrentStock--------------------------------------
// returns the currentStock of the product(movie)
int Product::getCurrentStock() const {
    return currentStock;
}
 
//------------------------decrementStock---------------------------------------
// decrements currentStock by 1 when the prodcut(movie) is borrowed.
void Product::decrementStock()  {
    currentStock--;
}
 
//------------------------incrementStock---------------------------------------
// increments currentStock by 1 when the prodcut(movie) is returned.
void Product::incrementStock()  {
    currentStock++;
}
