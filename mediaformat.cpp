#include "mediaformat.h"
 
//----------------------------Constructor--------------------------------------
// sets format name and id to default value
MediaFormat::MediaFormat() {
    name = "";
    id = '\0';
}
 
//----------------------------Destructor---------------------------------------
MediaFormat::~MediaFormat() {}
 
//----------------------------getID--------------------------------------------
// returns the id of the format of the given movie; D for DVD
char MediaFormat::getID() const {
    return id;
}
 
//----------------------------getName--------------------------------------------
// returns the name of the format of the given movie; i.e. DVD
string MediaFormat::getName() const {
    return name;
}
