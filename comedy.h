/*-----------------------------------------------------------------------------
  file comedy.h
  Specific movie class for movies belonging to the Comedy category.
    Sorted by title and then date.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Concrete class for movie
  Assumptions:
    -- Comedy is represented by the letter F in the data file
-----------------------------------------------------------------------------*/
 
#ifndef COMEDY_H
#define COMEDY_H
 
#include "movie.h"
 
class Comedy : public Movie {
public:
    Comedy();
    virtual ~Comedy();
    // Creates a new Comedy Movie object
    virtual Product* create() const;
    // sets the data of the movie from the input file
    // (i.e. movie category, director, date, title, etc.)
    virtual void setData(ifstream&);
    // sets the data of a dummy product, needed for error checking
    // and proper insertion.
    virtual void setDummyData(ifstream&);
    // overloaded operator< used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator<(const Product&) const;
    // overloaded operator== used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator==(const Product&) const;
    // displays all the information of the given product (movie) including
    // total stock and current stock.
    virtual void display() const;
    // displays same information as display minus the total stock and 
    // current stock of the product (movie)
    virtual void displayHistory() const;
};
#endif
