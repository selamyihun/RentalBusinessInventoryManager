#include "storemanager.h"
 
//-----------------------------------------------------------------------------
// main()
// This is the main function that creates a StoreManager class, a 
// ProductContainer class, and a CustomerTable class and runs
// the store activities. 
int main () {
    StoreManager manager;
    ProductContainer prodContainer;
    CustomerTable custContainer;
    if (manager.buildTree(prodContainer)) {
        if (manager.buildCustomerTable(custContainer)) {
            manager.runCommands(custContainer, prodContainer);
        }
    }
}
