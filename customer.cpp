//
// Created by tdasari on 3/7/25.
//

#include "customer.h"
#include <iostream>
#include <vector>
#include "transaction.h"
using namespace std;

/**
 * @brief Adds a transaction to the customer's transaction history.
 * 
 * @param transaction A pointer to the Transaction object to add.
 * @pre The Customer object has been created.
 * @post The transaction is added to the customer's transaction history.
 */
void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

/**
 * @brief Gets the customer's transaction history.
 * 
 * @return vector<Transaction*>* A pointer to the vector of Transaction pointers.
 * @pre The Customer object has been created.
 * @post Returns a pointer to the vector of Transaction pointers.
 */
vector<Transaction*>* Customer::getTransactions() {
    return &transactionHistory;
}

/**
 * @brief Displays the customer's transaction history.
 * 
 * @pre The Customer object has been created.
 * @post Outputs the customer's transaction history to the console.
 */
void Customer::displayHistory() {
    // reverse chronologically (what description says)

    // chronologically (which makes sense)
    for (int i = transactionHistory.size() - 1; i > -1; i--) {
        if (transactionHistory[i]->getTransactionType() == 'B' || transactionHistory[i]->getTransactionType() == 'R') {
            cout << transactionHistory[i]->getTransactionType() << " ";
            transactionHistory[i]->print();
        }
    }
    cout << endl;
}

/**
 * @brief Prints the customer's name.
 * 
 * @pre The Customer object has been created.
 * @post Outputs the customer's name to the console.
 */
void Customer::printName() {
    cout << first_name << " " << last_name;
}
