//
// Created by tdasari on 2/25/25.
//

#include "borrow.h"
#include "movie.h"
#include "store.h"
#include "customer.h"
#include <string>
#include <iostream>
using namespace std;

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

void Borrow::print() {
    cout << "Borrowed " << movie->getTitle() << " by " << movie->getDirector() << endl;
}
