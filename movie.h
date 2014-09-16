/*-----------------------------------------------------------------------------
  file movie.h
  Pure virtual Movie class that keeps track of
    director, title, and year of release.
    Inherits from Product.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Adds director, title, and year of release on top of name
    -- Still pure virtual
-----------------------------------------------------------------------------*/
 
#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "mediaformat.h"
#include "dvdformat.h"
#include <iomanip>
 
const int DEFAULT_STOCK = 10;
 
class Movie: public Product {
protected:
    string director, title;
    int year;
    MediaFormat* format;
 
public:
    Movie();
    virtual ~Movie();
    virtual Product* create() const = 0;
    // displays all the information of the given product (movie) including
    // total stock and current stock.
    virtual void display() const = 0;
    // displays same information as display minus the total stock and 
    // current stock of the product (movie)
    virtual void displayHistory() const = 0;
    // overloaded operator< used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator<(const Product&) const = 0;
    // overloaded operator== used to compare/sort movies based on specified 
    // criteria according to their category type.
    virtual bool operator==(const Product&) const = 0;
    // sets the data of the movie from the input file
    // (i.e. movie category, director, date, title, etc.)
    virtual void setData(ifstream&) = 0;
    // sets the data of a dummy product, needed for error checking
    // and proper insertion.
    virtual void setDummyData(ifstream&) = 0;
    MediaFormat* getMediaFormat() const;
};
 
#endif
