//-------------------------- transaction.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Header for the Transaction class, representing a generic 
// transaction. This class provides methods to get/set the transaction 
// type, and process transactions (to be overridden in derived classes).
// -------------------------------------------------------------------- 

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "store.h"

class Store;

class Transaction {
public:
    Transaction(); //Default Action constructor
    virtual void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    virtual void print();
    char getTransactionType(); //Returns the transaction type of the transaction object.
    void setTransactionType(char type); //Sets the transaction type of the transaction object.
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
};


#include "transaction.cpp"

#endif //TRANSACTION_H
