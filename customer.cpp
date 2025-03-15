//
// Created by tdasari on 3/7/25.
//

#include "customer.h"
#include <iostream>
#include <vector>
using namespace std;

void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

void Customer::displayHistory() {
    // reverse chronologically (what description says)

    // chronologically (which makes sense)
    for (Transaction* transaction : transactionHistory) {
        if (transaction->getTransactionType() == 'B' || transaction->getTransactionType() == 'R') {
            cout << transaction->getTransactionType() << " ";
            transaction->print();

        }
    }
    cout << endl;
}

void Customer::printName() {
    cout << first_name << " " << last_name;
}
