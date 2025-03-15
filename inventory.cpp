//-------------------------- inventory.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implements the `Inventory` class, which processes inventory display transactions. 
// -------------------------------------------------------------------- 

#include "inventory.h"
#include "store.h"
#include <iostream>
using namespace std;

// ---------- Inventory Constructor -----------
// Description: Default constructor for the `Inventory` class, setting the transaction type to 'I'.  
// preconditions: None.  
// postconditions: The `Inventory` transaction is initialized with type 'I'.  
Inventory::Inventory() {
    setTransactionType('I');
}

// ---------- process -----------
// Description: Processes an inventory transaction by printing the store’s current movie inventory.  
// preconditions: The store must be properly initialized with movie data.  
// postconditions: The store’s full inventory is printed in a formatted manner.  
void Inventory::process(Store* store) {
    // Print out the inventory, as in into the output:
    cout << ">> Store Inventory (I) has been requested:" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    store->displayInventory();
}

// ---------- print -----------
// Description: Prints a message indicating that an inventory request was made.  
// preconditions: None.  
// postconditions: A message is printed confirming the inventory request.  
void Inventory::print() {
    cout << ">> Store Inventory (I) has been requested." << endl;
}
