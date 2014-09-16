/*-----------------------------------------------------------------------------
   file mediaformat.h
  MediaFormat class for representing what format the movie was stored in.
  Authors: Selam Yihun & Jacob Jelovich
 
  Implementation:
    -- Holds only a name and format id as a member, also holds stock
    -- Members are protected, not private
  Assumptions:
    -- Will be used to represent a wide range of media formats
         (DVD, BluRay, VHS)
-----------------------------------------------------------------------------*/
 
#ifndef MEDIAFORMAT_H
#define MEDIAFORMAT_H
#include <string>
using namespace std;
 
class MediaFormat {
public:
    MediaFormat();
    ~MediaFormat();
    char getID() const;
    string getName() const;
 
protected:
    string name;
    char id;
};
 
 
#endif
