#include "dvdformat.h"
 
//----------------------------Constructor--------------------------------------
// sets the name of the fomat to DVD and id to D
DVDFormat::DVDFormat(): MediaFormat() {
    name = "DVD";
    id = 'D';
}
 
//----------------------------Destructor---------------------------------------
DVDFormat::~DVDFormat() {}
