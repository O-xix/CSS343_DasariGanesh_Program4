//
// Created by tdasari on 2/25/25.
//

#include "return.h"
#include "store.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include "transaction.h"
#include "borrow.h"
using namespace std;

/**
 * @brief Processes the return transaction.
 * 
 * @param store A pointer to the Store object.
 * @pre A valid Store object is passed as a parameter.
 * @post The movie is returned if it was previously borrowed by the customer.
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
 * @brief Prints the details of the return transaction.
 * 
 * @pre The Return object has been created and the movie has been set.
 * @post Outputs the details of the returned movie to the console.
 */
void Return::print() {
    cout << "Returned " << movie->getTitle() << " by " << movie->getDirector() << endl;
}