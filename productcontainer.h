/*-----------------------------------------------------------------------------
  file productcontainer.h
  Contains all instances of Product objects in the program.
    Made up of a hash table of products, where each index in 
    the product table holds a hash table for product category.
    Each index in the product category table holds a binary 
    search tree to actually store the objects.
  Authors: Selam Yihun & Jacob Jelovich
   
  Implementation:
    -- Each index in the product category table holds a binary search tree
         to actually store the objects.
  Assumptions:
    -- Product index by default (0) will be movies
    -- Category hash will be based on character input
-----------------------------------------------------------------------------*/
 
#ifndef PRODUCT_CONTAINER_H
#define PRODUCT_CONTAINER_H
#include "product.h"
#include "bintree.h"
#include <iomanip>
 
const int PRODUCT_SIZE = 1;
const int CATEGORY_SIZE = 26;
 
class ProductContainer {
private:
    int hashProduct() const;
    int hashCategory(char) const;
    BinTree* productTable[PRODUCT_SIZE][CATEGORY_SIZE];
 
public:
    ProductContainer();
    ~ProductContainer();
    // inserts the given product (movie) with the corrisponding category (char)
    // into the appropriate BinTree
    void append(Product*, char);
    // displays the contents of the BinTree to the console
    void printTree(char) const;
    // finds the given product using BinTree's retrieve method
    Product* findProduct(const Product&);
};
 
#endif
