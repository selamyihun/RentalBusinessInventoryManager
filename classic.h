/*-----------------------------------------------------------------------------
  file classic.h
  Specific movie class for movies belonging to the Classic category.
    Adds members for month of release and famous actor. 
    Sorted by release date and then famous actor.
  Authors:  Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Adds members for release month and famous actor
    -- Concrete class for movie
  Assumptions:
    -- Classics are represented by a C
-----------------------------------------------------------------------------*/
 
#ifndef CLASSIC_H
#define CLASSIC_H
 
#include "movie.h"
 
class Classic : public Movie {
 
private:
    int month;
    string actorFirst, actorLast;
 
 
public:
    Classic();
    virtual ~Classic();
    // Creates a new Classic Movie object
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
