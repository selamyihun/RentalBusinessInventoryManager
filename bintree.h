#include "bintree.h"
 
//------------------- constructors/destructor  -------------------------------
BinTree::BinTree() {
    root = NULL;
}
 
BinTree::~BinTree() {
    this->makeEmpty();
}
 
 
//--------------------- isEmpty & makeEmpty  ---------------------------------
bool BinTree::isEmpty() const {
    return (root == NULL);
}
 
void BinTree::makeEmpty() {
    makeEmptyHelper(root);
}
 
// private helper function
void BinTree::makeEmptyHelper(Node* subTree) {
    if (subTree != NULL) {
        makeEmptyHelper(subTree->left);
        makeEmptyHelper(subTree->right);
        delete subTree->data;
        subTree->data = NULL;
        delete subTree;
        subTree = NULL;
    }
    root = NULL;
}
 
 
//----------------------------- insert ---------------------------------------
bool BinTree::insert(Product* dataptr) {
    Node* ptr = new Node;   // exception is thrown if memory is not allocated
    ptr->data = dataptr;
    dataptr = NULL;
    ptr->left = ptr->right = NULL;
    if (isEmpty()) {
        root = ptr;
    }
    else {
        Node* current = root;
        bool inserted = false;
 
        // if item is less than current item, insert in left subtree.
        // if item is greater than current item, insert in right subtree.
        // otherwise it is a duplicate and not inserted.
        while (!inserted) {
            if (*ptr->data < *current->data) {
                if (current->left == NULL) {          // at leaf, insert left
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left;          // one step left
            }
            else if (*ptr->data == *current->data) {// duplicate not inserted
                delete ptr;
                ptr = NULL;
                return false;
            }
            else { 
                if (current->right == NULL) {         // at leaf, insert right
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right;         // one step right
                 
            }
        }
    }
    return true;
}
 
//--------------------------- retrieve ---------------------------------------
// Retrieve a Product* of a given object in the tree 
// (via pass-by-reference parameter). 
// Return whether found. The second parameter may initially be garbage, 
// will point to the actual object in the tree if it is found.
 Product* BinTree::retrieve(const Product& givenObj) const {
     return (retrieveHelper(root, givenObj));
 }
 
 // private helper function for retrieve
Product* BinTree::retrieveHelper(Node* subTree, const Product& target) const {
    if (subTree == NULL) {
        return NULL;
    } else if (*subTree->data == target) {
        return subTree->data;
    } else if (target < *subTree->data) {
        return retrieveHelper(subTree->left, target);
    } else {
        return retrieveHelper(subTree->right, target);
    }
}
 
 
 
//------------------------- operator<< ---------------------------------------
// display as an inorder traversal. 
// The Product class is responsible for displaying its data.
ostream& operator<<(ostream & output, const BinTree& subTree) {
    subTree.inorderHelper(subTree.root);
    output << endl;
    return output;
}
 
//------------------------- inorderHelper ------------------------------------
// private helper function for operator<<
void BinTree::inorderHelper(BinTree::Node* subTree) const {
    if (subTree != NULL) {
        inorderHelper(subTree->left);
        cout << " ";
        subTree->data->display();
        inorderHelper(subTree->right);
    }
}
