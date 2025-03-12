//
// Created by tdasari on 2/25/25.
//

#include "inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
    transaction_type = 'I';
}

void Inventory::process(Store* store) {
    // note: this is a placeholder method, because the inventory is not actually processed, but rather printed
    cout << ">> Inventory requested" << endl;
}

void Inventory::print(Store* store) {
    // Print out the inventory, as in into the output:
    cout << ">> Inventory (I):" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    store->displayInventory();
}