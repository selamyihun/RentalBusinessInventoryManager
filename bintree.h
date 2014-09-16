/** 
------------------------------------------------------------------------------
Class BinTree
Selam Yihun
Jacob Jelovich
This class is a simple binary search tree class (no remove) called BinTree.
a data file consisting of many lines is used to build binary trees. 
One line, which consists of many strings, will be used to build one tree.
Each line is terminated with the string "$$" . 
The NodeData, holding a string, is stored once in the tree.
Functionality includes:
    - making a tree empty and checking if a tree is empty.
    - inserting a given Product into a tree.
    - retrieving a given Product from a tree.
 
 
    Assumptions:
    - All data from in files is formated correctly 
      (string of chars where end of line is represented by $$).
    - Duplicates are not allowed in tree - deleted.
------------------------------------------------------------------------------  
*/
 
#ifndef BINTREE_H
#define BINTREE_H 
#include "product.h"
 
class BinTree { // you add class/method comments and assumptions
    friend ostream & operator<<(ostream &, const BinTree&);
 
public: 
 BinTree(); // constructor 
 BinTree(const BinTree &); // copy constructor 
 ~BinTree(); // destructor, calls makeEmpty 
 bool isEmpty() const; // true if tree is empty, otherwise false 
 void makeEmpty(); // make the tree empty so isEmpty returns true 
 bool insert(Product*); 
 Product* retrieve(const Product&) const;
 
 
private: 
 struct Node { 
 Product* data; // pointer to data object 
 Node* left; // left subtree pointer 
 Node* right; // right subtree pointer 
 }; 
 Node* root; // root of the tree 
  
 // utility functions 
 void makeEmptyHelper(Node*);
 Product* retrieveHelper(Node*, const Product&) const;
 void inorderHelper(Node*) const;
};
 
#endif
