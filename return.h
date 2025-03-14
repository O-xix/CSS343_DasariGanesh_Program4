//
// Created by tdasari on 2/25/25.
//

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
public:
    // Easy way: just create three constructors, one for each type of movie
    // Classics:
    Return(int customer_id, char media_type, char genre, int month_released, int year_released, string director) : transaction_type('B'), customer_id(customer_id), media_type(media_type), genre(genre), month_released(month_released), year_released(year_released), director(director) {}; //Default Action constructor
    // Comedy:
    Return(int customer_id, char media_type, char genre, string title, int year_released) : transaction_type('B'), customer_id(customer_id), media_type(media_type), genre(genre), title(title), year_released(year_released) {}; //Default Action constructor
    // Drama:
    Return(int customer_id, char media_type, char genre, string director, string title) : transaction_type('B'), customer_id(customer_id), media_type(media_type), genre(genre), director(director), title(title) {}; //Default Action constructor

    
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print();
private:
    char transaction_type; //Stores the character representing the transaction type in the input file, which is the only field the transactions have in common; all other fields exist in sub-/child classes.
    int customer_id = -1;
    char media_type = '@';
    char genre = '@';
    string director = "###";
    string actor = "###";
    string title = "###";
    int month_released = -1;
    int year_released = -1;

    Movie* movie;
};

#include "return.cpp"

#endif //RETURN_H
