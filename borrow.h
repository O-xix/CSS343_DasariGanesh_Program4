//
// Created by tdasari on 2/25/25.
//

#ifndef BORROW_H
#define BORROW_H

#include <string>
using namespace std;

#include "transaction.h"
#include "movie.h"
#include "store.h"

class Borrow : public Transaction {
public:
    // Easy way: just create three constructors, one for each type of movie
    // Classics:
    Borrow(int customer_id, char media_type, char genre, int month_released, int year_released, string actor) : customer_id(customer_id), media_type(media_type), genre(genre), month_released(month_released), year_released(year_released), actor(actor) {
        setTransactionType('B');
    }; //Default Action constructor
    // Comedy:
    Borrow(int customer_id, char media_type, char genre, string title, int year_released) : customer_id(customer_id), media_type(media_type), genre(genre), title(title), year_released(year_released) {
        setTransactionType('B');
    }; //Default Action constructor
    // Drama:
    Borrow(int customer_id, char media_type, char genre, string director, string title) : customer_id(customer_id), media_type(media_type), genre(genre), director(director), title(title) {
        setTransactionType('B');
    }; //Default Action constructor

    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print();

    Movie* getMovie();
private:
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

#include "borrow.cpp"

#endif //BORROW_H
