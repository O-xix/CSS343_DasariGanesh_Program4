//-------------------------- return.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implements the `Return` class, which processes the return of borrowed movies.  
// It verifies whether a customer has borrowed the movie before allowing the return  
// and updates the store’s inventory accordingly.  
// -------------------------------------------------------------------- 

#include "return.h"
#include "store.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include "transaction.h"
#include "borrow.h"
using namespace std;

 /**
 * @brief Processes the return of a movie by a customer.
 * 
 * @param store A pointer to the Store object that holds the customer and movie data.
 * @pre The customer must exist in the store, and the provided movie search criteria must be valid.
 * @post The movie stock is incremented, and the return transaction is added to the customer's transaction history if the movie was previously borrowed.
 */
void Return::process(Store* store) {
    movie = store->getMovie(media_type, genre, director, actor, title, month_released, year_released);
    if (movie == nullptr) {
        cout << ">> Movie not found; void Return::process(Store* store)" << endl;
        return;
    }
    vector<Transaction*>* tActionHistory = store->getCustomer(customer_id)->getTransactions();
    Borrow* borrowTransaction;
    for (int i = tActionHistory->size() - 1; i > -1; i--) {
        if (tActionHistory->at(i)->getTransactionType() == 'B') {
            borrowTransaction = dynamic_cast<Borrow*>(tActionHistory->at(i));
            if (borrowTransaction->getMovie() == movie) {
                store->getCustomer(customer_id)->addTransaction(this);
                movie->incrementStock();
                return;
            }
        }
    }
    cout << "ERROR: Customer " << customer_id << " has not borrowed " << movie->getTitle() << endl;
}

/**
 * @brief Prints a confirmation message indicating that a movie has been returned.
 * 
 * @pre The movie object must be valid and should have been processed.
 * @post A confirmation message is printed to the console displaying the movie's title and director.
 */
void Return::print() {
    cout << "Returned " << movie->getTitle() << " by " << movie->getDirector() << endl;
}