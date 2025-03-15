//
// Created by tdasari on 2/25/25.
//

#include "inventory.h"
#include "store.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor for the Inventory class. Sets the transaction type to 'I'.
 * 
 * @pre None
 * @post The transaction type is set to 'I'.
 */
Inventory::Inventory() {
    setTransactionType('I');
}

/**
 * @brief Processes the inventory transaction.
 * 
 * @param store A pointer to the Store object.
 * @pre A valid Store object is passed as a parameter.
 * @post The store's inventory is displayed.
 */
void Inventory::process(Store* store) {
    // Print out the inventory, as in into the output:
    cout << ">> Store Inventory (I) has been requested:" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    store->displayInventory();
}

/**
 * @brief Prints the details of the inventory transaction.
 * 
 * @pre The Inventory object has been created.
 * @post Outputs the details of the inventory request to the console.
 */
void Inventory::print() {
    cout << ">> Store Inventory (I) has been requested." << endl;
}
