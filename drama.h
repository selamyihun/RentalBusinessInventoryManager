/*-----------------------------------------------------------------------------
  file drama.h
  Specific movie class for movies belonging to the Drama category.
    Sorted by director and then title.
  Authors: Selam Yihun & Jacob Jelovich
 
  Assumptions:
    -- Dramas are represented by a D
-----------------------------------------------------------------------------*/
 
#ifndef DRAMA_H
#define DRAMA_H
 
#include "movie.h"
 
 
class Drama : public Movie {
public:
    Drama();
    virtual ~Drama();
    // Creates a new Drama Movie object
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
