//
// Created by tdasari on 2/25/25.
//

#include "history.h"
#include "customer.h"
#include "store.h"

#include <iostream>
using namespace std;

/**
 * @brief Processes the history transaction.
 * 
 * @param store A pointer to the Store object.
 * @pre A valid Store object is passed as a parameter.
 * @post The customer's transaction history is displayed if the customer is found.
 */
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

/**
 * @brief Prints the details of the history transaction.
 * 
 * @pre The History object has been created and the customer ID has been set.
 * @post Outputs the details of the history request to the console.
 */
void History::print() {
    cout << "History for " << customer_id << " requested." << endl;
}