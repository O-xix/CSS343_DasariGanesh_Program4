//-------------------------- transaction.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implementation for the Transaction class methods: setting 
// transaction type, processing, and printing transaction details.
// -------------------------------------------------------------------- 

#include "transaction.h"
#include "store.h"

/**
 * @brief Constructor for the Transaction class. Initializes the transaction_type to 
 * a default value of ' ' (empty space).
 * 
 * @pre None
 * @post `transaction_type` is set to a default value of ' '.
 */
Transaction::Transaction() {
    transaction_type = ' ';
}

/**
 * @brief Returns the transaction type of the current Transaction object.
 * 
 * @pre The Transaction object has been created and its `transaction_type` 
 * has been set.
 * @return char The current `transaction_type`.
 */
char Transaction::getTransactionType() {
    return transaction_type;
}

/**
 * @brief Sets the transaction type of the current Transaction object.
 * 
 * @param type A valid character representing the transaction type.
 * @pre `type` is a valid character representing the transaction type.
 * @post The `transaction_type` of the Transaction object is set to `type`.
 */
void Transaction::setTransactionType(char type) {
    transaction_type = type;
}

/**
 * @brief Prints the details of the current Transaction object, specifically 
 * the transaction type.
 * 
 * @pre The Transaction object has been created and `transaction_type` 
 * has been set.
 * @post Outputs the transaction type to the console.
 */
void Transaction::print() {
    cout << "Transaction Type: " << transaction_type << endl;
}

/**
 * @brief Processes the current transaction. This method is a placeholder and 
 * should be overridden by derived classes to implement specific transaction logic.
 * 
 * @param store A valid `store` object passed as a parameter to the method.
 * @pre A valid `store` object is passed as a parameter to the method.
 * @post Outputs a default message indicating that the method is not implemented 
 * for the base class.
 */
void Transaction::process(Store* store) {
    cout << "Processing transaction in Transaction class: WRONG" << endl;
}