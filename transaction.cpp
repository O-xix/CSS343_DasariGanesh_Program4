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