//
// Created by tdasari on 3/7/25.
//

#include "customer.h"
//#include "borrow.h"
#include <iostream>
#include <vector>
#include "transaction.h"
using namespace std;

void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

vector<Transaction*>* Customer::getTransactions() {
    return &transactionHistory;
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
