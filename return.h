//-------------------------- return.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Defines the `Return` class, a derived class of `Transaction`, that handles the return of borrowed movies.  
// This class allows customers to return movies of different genres.
// -------------------------------------------------------------------- 
#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
public:
    // Easy way: just create three constructors, one for each type of movie
    // Classics:
    Return(int customer_id, char media_type, char genre, int month_released, int year_released, string actor) : customer_id(customer_id), media_type(media_type), genre(genre), month_released(month_released), year_released(year_released), actor(actor) {
        setTransactionType('R');
    }; //Default Action constructor
    // Comedy:
    Return(int customer_id, char media_type, char genre, string title, int year_released) : customer_id(customer_id), media_type(media_type), genre(genre), title(title), year_released(year_released) {
        setTransactionType('R');
    }; //Default Action constructor
    // Drama:
    Return(int customer_id, char media_type, char genre, string director, string title) : customer_id(customer_id), media_type(media_type), genre(genre), director(director), title(title) {
        setTransactionType('R');
    }; //Default Action constructor

    
    void process(Store* store); //Inherited method to process the type of transaction where this method would be called, if ever it needed to be. Can be overloaded with additional parameters if necessary for a transaction.
    void print();
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

#include "return.cpp"

#endif //RETURN_H
