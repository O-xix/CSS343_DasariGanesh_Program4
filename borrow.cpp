//-------------------------- borrow.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This implementation file contains the methods of the `Borrow` 
// class, which handles the borrowing of movies in a movie rental system. 
// The `process` method attempts to borrow a movie from the store, checking 
// availability and updating stock.
// -------------------------------------------------------------------- 

#include "borrow.h"
#include "movie.h"
#include "store.h"
#include "customer.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Processes the borrow transaction.
 * 
 * @param store A pointer to the Store object.
 * @pre A valid Store object is passed as a parameter.
 * @post The movie is borrowed if it is available in stock.
 */
void Borrow::process(Store* store) {
    movie = store->getMovie(media_type, genre, director, actor, title, month_released, year_released);
    if (movie == nullptr) {
        cout << ">> Movie not found; void Borrow::process(Store* store)" << endl;
        return;
    }
    store->getCustomer(customer_id)->addTransaction(this);
    if (movie->getStock() == 0) {
        cout << ">> Movie out of stock." << endl;
        return;
    }
    movie->decrementStock();
}

/**
 * @brief Prints the details of the borrow transaction.
 * 
 * @pre The Borrow object has been created and the movie has been set.
 * @post Outputs the details of the borrowed movie to the console.
 */
void Borrow::print() {
    cout << "Borrowed " << movie->getTitle() << " by " << movie->getDirector() << endl;
}

/**
 * @brief Returns the movie associated with the borrow transaction.
 * 
 * @return Movie* A pointer to the borrowed movie.
 * @pre The Borrow object has been created and the movie has been set.
 * @post Returns a pointer to the borrowed movie.
 */
Movie* Borrow::getMovie() {
    return movie;
}