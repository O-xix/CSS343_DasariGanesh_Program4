//
// Created by tdasari on 2/25/25.
//

#include "history.h"



void History::process(Store* store) {
    Customer* customer = store->getCustomer(customer_id);
    if (customer == nullptr) {
        cout << ">> Customer " << customer_id << " not found." << endl;
        return;
    }
    cout << ">> Customer " << customer_id << " History (H) requested: " << endl;
    
    cout << "History for ";
    customer->printName();
    cout << ":" << endl;

    customer->displayHistory();
    cout << endl;
}