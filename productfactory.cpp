#include "productfactory.h"
 
//----------------------------Constructor--------------------------------------
// sets all indexes to NULL but index 2, 3, and 5 for their corrisponding movie
// category types.
ProductFactory::ProductFactory() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        prodFactory[i] = NULL;
    }
    prodFactory[5] = new Comedy();
    prodFactory[3] = new Drama();
    prodFactory[2] = new Classic();
 
}
 
//----------------------------Destructor---------------------------------------
ProductFactory::~ProductFactory() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if(prodFactory[i] != NULL) {
            delete prodFactory[i];
            prodFactory[i] = NULL;
        }
    }
}
 
//----------------------------createIt-----------------------------------------
// Creates a new movie of a specific category based on the char returned by the
// hash function; C = Classic, F = Comedy, D = Drama.
Product* ProductFactory::createIt(char ch) const {
    int subscript = hash(ch);             // would do error checking
    if(prodFactory[subscript] == NULL) {
        return NULL;
    }
    return prodFactory[subscript]->create();
}
 
//----------------------------hash-----------------------------------------
int ProductFactory::hash(char ch) const { return ch-'A'; }
