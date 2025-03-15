//-------------------------- inventory.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Defines the `Inventory` class, a derived class of `Transaction`, which handles the display  
// of the store's entire movie inventory.
// -------------------------------------------------------------------- 

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
#include "store.h"

class Inventory : public Transaction {
public:
    Inventory(); //Default Action constructor
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print();
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
};

#include "inventory.cpp"

#endif //INVENTORY_H
