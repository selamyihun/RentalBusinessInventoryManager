#include "drama.h"
 
//----------------------------Constructor--------------------------------------
// sets format to default value
Drama::Drama() : Movie() { 
    format = NULL;
}
 
//----------------------------Destructor---------------------------------------
Drama::~Drama() {
    if (format != NULL) {
        delete format;
        format = NULL;
    }
}
 
//----------------------------Create-------------------------------------------
// Creates a new Drama Movie object
Product* Drama::create() const {return new Drama();}
 
//----------------------------operator<----------------------------------------
// compares Comedy movies by director, then title
bool Drama::operator<(const Product& rightProduct) const {
    if(director < static_cast<const Drama&>(rightProduct).director) {
        return true;
    } else if(director == static_cast<const Drama&>(rightProduct).director && 
        title < static_cast<const Drama&>(rightProduct).title) {
            return true;
    } 
    return false;
}
 
//----------------------------operator==---------------------------------------
// compares Comedy movies by director, then title
bool Drama::operator==(const Product& rightProduct) const {
    if(director == static_cast<const Drama&>(rightProduct).director && 
        title == static_cast<const Drama&>(rightProduct).title) {
            return true;
    }
    return false;
}
 
//----------------------------setData----------------------------------------
// sets the data of the Classic movie from the input file
// (i.e. movie category, director, date (year), title, 
// and total and current stock).
void Drama::setData(ifstream& infile){
    category = 'D';
    infile.get();                       // get (ignore) blank before director
    getline(infile, director, ',');     // input director
 
    infile.get();                       // get (and ignore) blank before title
    getline(infile, title, ',');        // input title
 
    infile.get();                       // get (and ignore) blank before actor
    infile >> year;                       // input year
    format = new DVDFormat();           // sets the format to DVD
    currentStock = totalStock = DEFAULT_STOCK;  // initializes the stock to 10
}
 
void Drama::setDummyData(ifstream& infile){
    category = 'D';
    infile.get();                       // get (ignore) blank before director
    getline(infile, director, ',');     // input director
 
    infile.get();                       // get (and ignore) blank before title
    getline(infile, title, ',');        // input title
}
 
//----------------------------display------------------------------------------
// displays all the information of the given product (movie) including
// total stock and current stock.
// e.g. 10 0 Steven Spielberg, Schindler's List, 1993
void Drama::display() const {
    cout << right << setw(3) << currentStock << right << setw(4) 
        << totalStock - currentStock << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) 
        << director.substr(0, 16) << setw(5) << year << endl;
}
 
//----------------------------displayHistory-----------------------------------
// displays same information as display minus the total stock and 
// current stock of the product (movie).
// e.g. Steven Spielberg, Schindler's List, 1993
void Drama::displayHistory() const {
    cout << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) 
        << director.substr(0, 16) << setw(5) << year << endl;
}
