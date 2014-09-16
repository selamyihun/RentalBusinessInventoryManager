#include "movie.h"
 
//----------------------------Constructor--------------------------------------
// sets productType, format, year, director, and title to their 
// default values
Movie::Movie() : Product() { 
    productType = "Movie";
    format = NULL;
    year = 0;
    director = title = "";
}
 
//----------------------------Destructor---------------------------------------
Movie::~Movie() { }
 
//----------------------------getMediaFormat--------------------------------------
// returns the media format of the movie (i.e. DVD)
MediaFormat* Movie::getMediaFormat() const { 
    return format;
}
