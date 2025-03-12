//
// Created by tdasari on 2/25/25.
//

#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
#include "movie.h"
#include "store.h"

class Borrow : public Transaction {
public:
    Borrow(int customer_id, char media_type, Movie movie) : transaction_type('B'), customer_id(customer_id), media_type(media_type), movie(movie) {}; //Default Action constructor
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print(Store* store);
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
    int customer_id;
    char media_type;
    
    Store* store;
};



#endif //BORROW_H
