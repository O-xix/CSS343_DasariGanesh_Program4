//
// Created by tdasari on 2/25/25.
//

#include "history.h"



void History::process(Store* store) {
    //note: this is a placeholder method, because the customer history is not actually processed, but rather printed
    cout << ">> Customer " << customer_id << " history requested" << endl;
}

void History::print(Store* store) {
    // @todo: There's no way to get the customer object from the customer_id
    Customer* customer = store->getCustomer(customer_id);
    if (customer == nullptr) {
        cout << "Customer not found" << endl;
        return;
    }
    cout << "History for " << customer-> << endl;
}