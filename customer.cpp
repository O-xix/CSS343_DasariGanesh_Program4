//
// Created by tdasari on 3/7/25.
//

#include "customer.h"

void Customer::addTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Customer::displayHistory() {
    // reverse chronologically (what description says)

    // chronologically (which makes sense)
    for (int i = 0; i < transactionHistory.size(); i++) {
      transactionHistory[i].print();
    }
}

