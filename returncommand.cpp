#include "returncommand.h"
 
//----------------------------Constructor--------------------------------------
// sets the name of the command to Return
ReturnCommand::ReturnCommand() : Command() {  
    name = "Return";
}
 
 
//-----------------------------------------------------------------------------
// execute()
// This function takes care of the transaction than needs to be performed
// by the command object. It has an input file stream passed to it
// so that it can read the Customer Id, the product that needs to 
// have the transaction performed on. The function then increments
// the stock of the product if the product is found and it is returnable
// This function is not const because it appends this object to the 
// customer's history.
void ReturnCommand::execute(ifstream& infile) {
    int id = 0;
    char line[MAX_LINE_2];
     
    infile >> id;
     
    if(customerContainer->getCustomer(id) == NULL){
        cout << endl << "Customer with ID " << id << " not found!" << endl;
        infile.getline(line, MAX_LINE_2);
    } else {
        executeHelper(infile, id);
    }
}
 
//-----------------------------------------------------------------------------
// executeHelper()
//  Helper function for execute()
void ReturnCommand::executeHelper(ifstream& infile, int id) {
    char mediaType = '\0';
    char ch = '\0';
    char line[MAX_LINE_2];
    ProductFactory prodFactory;
    customer = customerContainer->getCustomer(id); 
 
    infile >> mediaType;
    infile >> ch;
 
    Product* p = prodFactory.createIt(ch);
    if (p == NULL) {
        cout << endl << ch << " is an invalid category type!" << endl;
        infile.getline(line, MAX_LINE_2);
    }
    else {
        p->setDummyData(infile);
        product = productContainer->findProduct(*p);
         
        if (product == NULL){
            cout << endl;
            cout << "Product not found:" << endl;
            p->displayHistory();
        } else if
            (static_cast<const Movie&>(*product).getMediaFormat()->getID()
            != mediaType) {
                cout << endl << mediaType 
                    << " is and invalid media type!" << endl;
        } else {
            if(checkIfReturnable()){
                product->incrementStock();
                customer->appendHistory(*this);
            }
            else {
                cout << endl 
                    << "Product that is not borrowed is not returnable:"
                    << endl;
                product->displayHistory();
            }
        }
        delete p;               //done with our dummy product
        p = NULL;
    }
}
 
//-----------------------------------------------------------------------------
// checkIfReturnable()
//  Checks to see if a product is returnable. Returns true if returnable
//  false otherwise
bool ReturnCommand::checkIfReturnable() const {
    bool isReturnable = false;
    int prodWithCustomer = 0;
    CustomerHistory temp = *customer->getHistory();
    list<Command*> tempList = *temp.getCommandHistory();
    list<Command*>::const_iterator ptr = tempList.begin();
    for (ptr; ptr != tempList.end(); ++ptr){
        if ((*ptr)->getProduct() == product) {
            if((*ptr)->getName() == "Borrow"){
                prodWithCustomer++;
            }
            else if((*ptr)->getName() == name){
                prodWithCustomer--;
            }
        }
    }   
    return (prodWithCustomer > 0);
}
 
//-----------------------------------------------------------------------------
// create()
// This function creates a new instance of BorrowCommand object
Command* ReturnCommand::create() const {
    return new ReturnCommand();
}
 
//-----------------------------------------------------------------------------
// setData()
// Sets the active ProductContainer and CustomerTable pointers to the command
void ReturnCommand::setData(ProductContainer* container, 
                            CustomerTable* customers) {
    productContainer = container;
    customerContainer = customers;
}
 
//-----------------------------------------------------------------------------
// printData()
// Prints the command data to the console, it prints the MediaFormat, the
// name of the command and the product the command was performed on
void ReturnCommand::printData() const {
     cout << static_cast<const Movie&>(*product).getMediaFormat()->getName();
     cout << ' ' << name;
     product->displayHistory();
}
