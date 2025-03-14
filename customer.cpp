//
// Created by tdasari on 3/7/25.
//

#include "customer.h"
#include <iostream>
#include <vector>
using namespace std;

void Customer::addTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Customer::displayHistory() {
    // reverse chronologically (what description says)

    // chronologically (which makes sense)
    for (int i = 0; i < transactionHistory.size(); i++) {
      if (transactionHistory[i].getTransactionType() == 'B' || transactionHistory[i].getTransactionType() == 'R') {
        cout << transactionHistory[i].getTransactionType() << " ";
        transactionHistory[i].print();
        cout << endl;
        
      }
    }
}

void Customer::printName() {
    cout << first_name << " " << last_name;
}
