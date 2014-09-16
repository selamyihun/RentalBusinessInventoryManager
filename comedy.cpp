#include "comedy.h"
 
//----------------------------Constructor--------------------------------------
// sets format to default value
Comedy::Comedy() : Movie() {
    format = NULL;
}
 
//----------------------------Destructor---------------------------------------
Comedy::~Comedy() {
    if (format != NULL){
        delete format;
        format = NULL;
    }
}
 
//----------------------------Create-------------------------------------------
// Creates a new Comedy Movie object
Product* Comedy::create() const {return new Comedy();}
 
//----------------------------operator<----------------------------------------
// compares Comedy movies by title, then date
bool Comedy::operator<(const Product& rightProduct) const {
    if(title < static_cast<const Comedy&>(rightProduct).title) {
        return true;
    } else if(title == static_cast<const Comedy&>(rightProduct).title && 
        year < static_cast<const Comedy&>(rightProduct).year) {
            return true;
    } 
    return false;
}
 
//----------------------------operator==---------------------------------------
// compares Comedy movies by title, then date
bool Comedy::operator==(const Product& rightProduct) const {
    if(year == static_cast<const Comedy&>(rightProduct).year && 
        title == static_cast<const Comedy&>(rightProduct).title) {
            return true;
    }
    return false;
}
 
//----------------------------setData----------------------------------------
// sets the data of the Classic movie from the input file
// (i.e. movie category, director, date (year), title, 
// and total and current stock).
void Comedy::setData(ifstream& infile){
    category = 'F';
    infile.get();                       // get (ignore) blank before director
    getline(infile, director, ',');     // input director
 
    infile.get();                       // get (ignore) blank before title
    getline(infile, title, ',');        // input title
 
    infile >> year;                       // input year
    format = new DVDFormat();           // sets the format to DVD
    currentStock = totalStock = DEFAULT_STOCK;  // initializes the stock to 10
}
 
//----------------------------setDummyData-------------------------------------
// sets the data of a dummy product, needed for error checking
// and proper insertion.
void Comedy::setDummyData(ifstream& infile){
    category = 'F';
    infile.get();                       // get (ignore) blank before title
    getline(infile, title, ',');        // input title
    infile >> year;                       // input year
}
 
//----------------------------display------------------------------------------
// displays all the information of the given product (movie) including
// total stock and current stock.
// e.g. 10 0 Gore Verbinski, Pirates of the Caribbean, 2003
void Comedy::display() const {
    cout << right << setw(3) << currentStock << right << setw(4) 
        << totalStock - currentStock << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) 
        << director.substr(0, 16) << setw(5) << year << endl;
}
 
//----------------------------displayHistory-----------------------------------
// displays same information as display minus the total stock and 
// current stock of the product (movie).
// e.g. Gore Verbinski, Pirates of the Caribbean, 2003
void Comedy::displayHistory() const {
    cout << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) 
        << director.substr(0, 16) << setw(5) << year << endl;
}
