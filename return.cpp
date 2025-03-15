//
// Created by tdasari on 2/25/25.
//

#include "return.h"
#include "store.h"
#include "customer.h"
#include <iostream>
using namespace std;

void Return::process(Store* store) {
    movie = store->getMovie(media_type, genre, director, actor, title, month_released, year_released);
    if (movie == nullptr) {
        cout << ">> Movie not found; void Return::process(Store* store)" << endl;
        return;
    }
    store->getCustomer(customer_id)->addTransaction(*this);
    if (movie->getStock() == 0) {
        cout << ">> Movie out of stock." << endl;
        return;
    }
    movie->decrementStock();
}

void Return::print() {
    cout << "Returned " << movie->getTitle() << " by " << movie->getDirector() << endl;
}