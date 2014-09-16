#include "classic.h"
 
//----------------------------Constructor--------------------------------------
// sets format, year, month, actorFirst and actorLast to their 
// default values
Classic::Classic() : Movie() {
    format = NULL;
    month = 0;
    actorFirst = actorLast = "";
}
 
//----------------------------Destructor---------------------------------------
Classic::~Classic() {
    if(format != NULL)
    {
        delete format;
        format = NULL;
    }
}
 
//----------------------------Create-------------------------------------------
// Creates a new Classic Movie object
Product* Classic::create() const {return new Classic();}
 
//----------------------------operator<----------------------------------------
// compares Classic movies by date, then famous actor
bool Classic::operator<(const Product& rightProduct) const {
    if(year < static_cast<const Classic&>(rightProduct).year) {
        return true;
    } else if(year == static_cast<const Classic&>(rightProduct).year && 
        month < static_cast<const Classic&>(rightProduct).month) {
            return true;
    } else if(year == static_cast<const Classic&>(rightProduct).year && 
        month == static_cast<const Classic&>(rightProduct).month &&
        actorLast < static_cast<const Classic&>(rightProduct).actorLast) {
            return true;
    }else if(year == static_cast<const Classic&>(rightProduct).year && 
        month == static_cast<const Classic&>(rightProduct).month &&
        actorLast == static_cast<const Classic&>(rightProduct).actorLast &&
        actorFirst < static_cast<const Classic&>(rightProduct).actorFirst) {
            return true;
    }
    return false;
}
 
//----------------------------operator==---------------------------------------
// compares Classic movies by date, then famous actor
bool Classic::operator==(const Product& rightProduct) const {
    if(year == static_cast<const Classic&>(rightProduct).year && 
        month == static_cast<const Classic&>(rightProduct).month &&
        actorLast == static_cast<const Classic&>(rightProduct).actorLast &&
        actorFirst == static_cast<const Classic&>(rightProduct).actorFirst) {
            return true;
    }
    return false;
}
 
//----------------------------setData----------------------------------------
// sets the data of the Classic movie from the input file
// (i.e. movie category, director, date (year & month), title, 
// famous actor first and last name, and total and current stock).
void Classic::setData(ifstream& infile){
    category = 'C';
    infile.get();                       // get (ignore) blank before director
    getline(infile, director, ',');     // input director
    
    infile.get();                       // get (and ignore) blank before title
    getline(infile, title, ',');        // input title
    
    infile.get();                       // get (and ignore) blank before actor
    infile >> actorFirst >> actorLast;  // input star's name
    infile >> month >> year;            // input month and year
    format = new DVDFormat();           // sets the format to DVD
    currentStock = totalStock = DEFAULT_STOCK;  // initializes the stock to 10
}
 
//----------------------------setDummyData-------------------------------------
// sets the data of a dummy product, needed for error checking
// and proper insertion.
void Classic::setDummyData(ifstream& infile){
    category = 'C';
    infile >> month >> year;    // input month and year
    infile >> actorFirst >> actorLast;  // input star's name
}
 
//----------------------------display------------------------------------------
// displays all the information of the given product (movie) including
// total stock and current stock.
// e.g. 10 0 George Cukor, Holiday, K Hepburn 9 1938
void Classic::display() const {
    cout << right << setw(3) << currentStock << right << setw(4) 
        << totalStock - currentStock << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) << director.substr(0, 16) 
        << setw(5) << year << right << setw(3) << month << "  "
        // truncate actors first name to stay within 80 lines on console
        << actorFirst.substr(0, 1) << ' ' << actorLast << endl;
}
 
//----------------------------displayHistory-----------------------------------
// displays same information as display minus the total stock and 
// current stock of the product (movie).
// e.g. George Cukor, Holiday, K Hepburn 9 1938
void Classic::displayHistory() const {
    cout << "  " << left << setw(23) 
        << title.substr(0, 21) << left << setw(18) << director.substr(0, 16) 
        << setw(5) << year << right << setw(3) << month << "  "
        // truncate actors first name to stay within 80 lines on console
        << actorFirst.substr(0, 1) << ' ' << actorLast << endl; 
}
