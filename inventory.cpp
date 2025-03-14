//
// Created by tdasari on 2/25/25.
//

#include "inventory.h"
#include "store.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
    setTransactionType('I');
}

void Inventory::process(Store* store) {
    // Print out the inventory, as in into the output:
    cout << ">> Store Inventory (I) has been requested:" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    store->displayInventory();
}