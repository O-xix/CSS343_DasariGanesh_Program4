//
// Created by tdasari on 2/25/25.
//

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return {
public:
    Return(int customer_id, char media_type) : transaction_type('R'), customer_id(customer_id), media_type(media_type) {}; //Default Action constructor
    virtual void process(); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    virtual void print();
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
    int customer_id;
    char media_type;
};



#endif //RETURN_H
