//
// Created by tdasari on 2/25/25.
//

#include "transaction.h"

Transaction::Transaction() {
    transaction_type = ' ';
}

char Transaction::getTransactionType() {
    return transaction_type;
}

void Transaction::setTransactionType(char type) {
    transaction_type = type;
}

void Transaction::print() {
    cout << "Transaction Type: " << transaction_type << endl;
}

// Define the process method
void Transaction::process(Store* store) {
    cout << "Processing transaction in Transaction class: WRONG" << endl;
}