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

// ---------- Transaction Constructor -----------
// Description: Constructor for the Transaction class. Initializes the transaction_type to 
// a default value of ' ' (empty space).
// Preconditions: None
// Postconditions: `transaction_type` is set to a default value of ' '.
Transaction::Transaction() {
    transaction_type = ' ';
}

// ---------- getTransactionType -----------
// Description: Returns the transaction type of the current Transaction object.
// Preconditions: The Transaction object has been created and its `transaction_type` 
// has been set.
// Postconditions: Returns the current `transaction_type`.
char Transaction::getTransactionType() {
    return transaction_type;
}

// ---------- setTransactionType -----------
// Description: Sets the transaction type of the current Transaction object.
// Preconditions: 'type` is a valid character representing the transaction type.
// Postconditions: The `transaction_type` of the Transaction object is set to `type`.
void Transaction::setTransactionType(char type) {
    transaction_type = type;
}

// ---------- print -----------
// Description: Prints the details of the current Transaction object, specifically 
// the transaction type.
//
// Preconditions: The Transaction object has been created and `transaction_type` 
// has been set.
//
// Postconditions: Outputs the transaction type to the console.
void Transaction::print() {
    cout << "Transaction Type: " << transaction_type << endl;
}

// ---------- process -----------
// Description: Processes the current transaction. This method is a placeholder and 
// should be overridden by derived classes to implement specific transaction logic.
//
// Preconditions: A valid `store` object is passed as a parameter to the method.
// 
// Postconditions: Outputs a default message indicating that the method is not implemented 
// for the base class.
void Transaction::process(Store* store) {
    cout << "Processing transaction in Transaction class: WRONG" << endl;
}