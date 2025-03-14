//
// Created by tdasari on 2/25/25.
//

#include "history.h"
#include "customer.h"
#include "store.h"

#include <iostream>
using namespace std;

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

void History::print() {
  cout << "History for " << customer_id << "requested." << endl;
}