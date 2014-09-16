#include "storemanager.h"
 
//------------------------------buildTree--------------------------------------
// builds the respective BinTrees of pruducts from the 
// provided movie data file. Returns true if data4movies.txt is read in, 
// false otherwise. If buildTree is not successful, buildCustomerTable and
// runCommands will not be executed.
bool StoreManager::buildTree(ProductContainer& prodContainer){
    bool success = false;
    ifstream infile("data4movies.txt");
    if(!infile) { cout << "Product file could not be opened." << endl; } 
    else {
        success = true;
        ProductFactory prodFactory;
 
        char ch;
        char line[MAX_LINE];
 
        for(;;){
            infile >> ch;
            if (infile.eof()) { break; }    
            Product* p = prodFactory.createIt(ch);
            if (p == NULL) {
                infile.getline(line, MAX_LINE);
                cout << endl << ch << " is an invalid product type!" << endl;
            }
            else {
                p->setData(infile);
                prodContainer.append(p, ch);
            }
        }
    }
    return success;
}
 
//-------------------------buildCustomerTable----------------------------------
// builds a table of customers from the provided customer data file
// Returns true if data4customers.txt is read in, 
// false otherwise. If buildCustomerTable is not successful,
// runnCommands or buildTree will not be executed.
bool StoreManager::buildCustomerTable(CustomerTable& customerTable) {
    bool success = false;
    ifstream infile("data4customers.txt");
    if(!infile) { cout << "Customer file could not be opened." << endl; } 
    else {
        success = true;
        int id;
        char line[MAX_LINE];
 
        for(;;) {
            infile >> id;
            if (infile.eof()) { break; }
            if (customerTable.getCustomer(id) == NULL && id < DEFAULT_SIZE
                && id > 0) {
                    Customer* p = new Customer();
                    p->setData(infile, id);
                    customerTable.setCustomer(id, p);
            }
            else {
                cout << endl << 
                    "That ID has already been taken or it is invalid!"
                    << endl;
                infile.getline(line, MAX_LINE); //gets if id is invalid
            }
        }
    }
    return success;
}
 
//-------------------------runCommands-----------------------------------------
// runs commands according to input form the provided command data file.
// Returns true if data4commands.txt is read in, 
// false otherwise. If runnCommands is not successful,
//   buildCustomerTable or buildTree will not be executed.
void StoreManager::runCommands(CustomerTable& custTable, 
                                ProductContainer& prodContainer) {
    CommandFactory comFactory;
    CommandContainer comContainer;
    ifstream infile("data4commands.txt");
    if(!infile) { cout << "Command file could not be opened." << endl; } 
    else {;
        char ch;
        char line[MAX_LINE];
 
        for(;;) {
            infile >> ch;
            if (infile.eof()) { break; }
            Command* p = comFactory.createIt(ch);
            if(p == NULL) {
                cout << endl << ch << " is an invalid command type!" << endl;
                //gets line if command is invalid
                infile.getline(line, MAX_LINE); 
                 
            }
            else {
                p->setData(&prodContainer, &custTable);
                p->execute(infile);
                comContainer.appendCommand(*p);
            }
        }
    }
}
