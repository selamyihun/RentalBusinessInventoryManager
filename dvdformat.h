/*-----------------------------------------------------------------------------
  file dvdformat.h
  Specific type of MediaFormat for DVDs.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation: 
    -- Inherits from the Media Format class
    -- Currently has no members, but could handle information about price
-----------------------------------------------------------------------------*/
 
#ifndef DVD_FORMAT_H
#define DVD_FORMAT_H
#include "mediaformat.h"
#include <string>
 
class DVDFormat: public MediaFormat {
public:
    DVDFormat();
    ~DVDFormat();
};
 
#endif
