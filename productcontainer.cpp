#include "productcontainer.h"
 
//----------------------------Constructor--------------------------------------
// creates empty BinTrees at each index
ProductContainer::ProductContainer() {
    for(int i = 0; i < PRODUCT_SIZE; i++){
        for(int j = 0; j < CATEGORY_SIZE; j++){
            productTable[i][j] = new BinTree();
        }
    }
}
 
//----------------------------Destructor---------------------------------------
ProductContainer::~ProductContainer() { 
    for(int i = 0; i < PRODUCT_SIZE; i++){
        for(int j = 0; j < CATEGORY_SIZE; j++){
            delete productTable[i][j];
            productTable[i][j] = NULL;
        }
    }
}
 
//----------------------------append-------------------------------------------
// inserts the given product (movie) with the corrisponding category (char)
// into the appropriate BinTree.
void ProductContainer::append(Product* currentProduct, char theCategory) {
    int product = hashProduct();
    int category = hashCategory(theCategory);
    productTable[product][category]->insert(currentProduct);
}
 
//----------------------------findProduct--------------------------------------
// finds the given product using BinTree's retrieve method
Product* ProductContainer::findProduct(const Product& target) {
    int product = hashProduct();
    int category = hashCategory(target.getCategory());
    return productTable[product][category]->retrieve(target);
}
//----------------------------hashProduct--------------------------------------
// Since the movie store only has one product at the moment, the default hashes
// the movie products to index 0.
int ProductContainer::hashProduct() const {return 0;}
 
//----------------------------hashCategory-------------------------------------
// Hashes the movie category to the appropriate index based on the char 
// provided.
int ProductContainer::hashCategory(char category) const {
    return category - 'A';
}
 
 
//----------------------------printTree----------------------------------------
// displays the contents of the movie BinTree to the console. 
// Content is displayed: 
// *IN* *OUT*
// DVD  DVD TITLE                DIRECTOR         YEAR MO  ACTOR
// 9   1   Holiday               George Cukor     1938  9  C Grant
// for Classic movies, Comedies and Dramas are displayed the same but do not have
// month or famous actor.
void ProductContainer::printTree(char theCategory) const {
    int product = hashProduct();
    int category = hashCategory(theCategory);
    cout << right << setw(2) << "*IN* " << right << setw(4) 
        << "*OUT*" << endl;
    cout << right << setw(4) << "DVD" << right << setw(4) 
        << "DVD" << "  " << left << setw(23) 
        << "TITLE" << left << setw(18) 
        << "DIRECTOR" << setw(5) << "YEAR";
    if (theCategory == 'C') {
        cout << " MO " << " ACTOR"; 
    }
    cout << endl << *productTable[product][category];
}
