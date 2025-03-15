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

// ---------- process -----------
// Description: Processes a return transaction by verifying if the customer has borrowed  
// the movie and updating the store’s inventory accordingly.  
// preconditions: The movie exists in the store’s inventory. 
// The customer ID is valid and corresponds to an existing customer.  
// The movie must have been previously borrowed by the customer.  
// postconditions: If a matching borrow transaction is found, the return is 
// recorded, and the movie’s stock is increased, otherwise error message is displayed  
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

// ---------- print -----------
// Description: Prints a message confirming the return of a movie.  
// preconditions: The movie object must be valid and exist in the store’s inventory.  
// postconditions: A formatted message is printed, displaying the movie title and director.  
void Return::print() {
    cout << "Returned " << movie->getTitle() << " by " << movie->getDirector() << endl;
}