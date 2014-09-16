/*-----------------------------------------------------------------------------
  file product.h
  Pure virtual class representing a general product,
    with name as the only member. Provides functions
    that all products must override.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Holds only a  name as a member. Everything else is pure virtual functions
    -- Members are protected, not private
Assumptions:
    -- Movies are the default product
-----------------------------------------------------------------------------*/
 
#ifndef PRODUCT_H
#define PRODUCT_H
 
#include <string>
#include <iostream>
#include <fstream>
 
using namespace std;
 
class Product {
protected:
    string productType;
    int totalStock, currentStock;
    char category;
 
public:
    Product();
    virtual ~Product();
    // sets the data of the product from the input file
    // (i.e. movie category, director, date, title, etc.)
    virtual void setData(ifstream&) = 0;
    // sets the data of a dummy product, needed for error checking
    // and proper insertion.
    virtual void setDummyData(ifstream&) = 0;
    // returns the char that represents the category of the movie.
    char getCategory() const;
    // returns the current stock of the movie.
    int getCurrentStock() const;
    // reduces the current stock of the movie when it is borrowed.
    void decrementStock();
    // increments the current stock of the movie when it is returned.
    void incrementStock();
    // overloaded operator< used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator<(const Product&) const = 0;
    // overloaded operator== used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator==(const Product&) const = 0;
    // creates a new movie product
    virtual Product* create() const = 0;
    // displays all the information of the given product (movie) including
    // total stock and current stock.
    virtual void display() const = 0;
    // displays same information as display minus the total stock and 
    // current stock of the product (movie)
    virtual void displayHistory() const = 0;
};
 
#endif
