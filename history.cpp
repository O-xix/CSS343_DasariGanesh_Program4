//-------------------------- history.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implements the `History` class methods for handling and displaying a customer's transaction history.
// -------------------------------------------------------------------- 

#include "history.h"
#include "customer.h"
#include "store.h"

#include <iostream>
using namespace std;

// ---------- process -----------
// Description: The `process` method retrieves the transaction history 
// for a specific customer by their customer ID.  
// Preconditions: The `store` pointer is valid, and the store has a list of customers.  
// The `customer_id` must correspond to a valid customer in the store.  
// Postconditions: If the customer is found, their transaction 
// history is printed, other wise error message is printed.  
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

// ---------- print -----------
// Description: The `print` method prints a message stating 
// that the transaction for the requested customer's history has been made.  
// Preconditions: The `customer_id` is a valid integer.  
// Postconditions: A simple message stating the history request for the customer is printed. 
void History::print() {
  cout << "History for " << customer_id << "requested." << endl;
}