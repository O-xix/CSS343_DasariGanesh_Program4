//
// Created by tdasari on 2/25/25.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
#include "store.h"

class Inventory : public Transaction {
public:
    Inventory(); //Default Action constructor
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print(Store* store);
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.

    Store* store;
};



#endif //INVENTORY_H
