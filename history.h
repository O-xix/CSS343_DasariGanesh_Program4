//-------------------------- history.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Defines the `History` class, a derived class of `Transaction`, 
// which processes a customer's transaction history. 
// -------------------------------------------------------------------- 

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"
#include "store.h"
#include "customer.h"

class History : public Transaction {
public:
    History(int customer_id) : transaction_type('H'), customer_id(customer_id) {}; //Default Action constructor
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print(); // Unused
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
    int customer_id;
};

#include "history.cpp"

#endif //HISTORY_H
