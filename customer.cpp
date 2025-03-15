//
// Created by tdasari on 3/7/25.
//

#include "customer.h"
#include <iostream>
#include <vector>

#include "borrow.h"
using namespace std;

void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

bool Customer::containsBorrowTransaction(Movie* other_movie) {
    Borrow* borrow;
    for (int i = transactionHistory.size() - 1; i > -1; i--) {
        if (transactionHistory[i]->getTransactionType() == 'B') {
            borrow = dynamic_cast<Borrow*>(transactionHistory[i]);
            if (borrow->getMovie() == other_movie) {
                return true;
            }
        }
    }
    return false;
}

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

void Customer::printName() {
    cout << first_name << " " << last_name;
}
