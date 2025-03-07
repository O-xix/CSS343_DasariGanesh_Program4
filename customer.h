//
// Created by tdasari on 3/7/25.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer{
public:
    Customer(); //Default constructor
    void addTransaction(const Transaction& transaction); //Add a transaction the Customer has made to the transactionHistory for that Customer
    void displayHistory(); //Prints out history in chronological order as the transaction appears in the transactions file.
private:
    int customer_id; //Stores unique customer ID
    string last_name; //Stores last name of the customer
    string first_name; //Stores first name of the customer
    vector<Transaction> transactionHistory; // Stores transaction history of the customer in the order that is in the input transaction file
}




#endif //CUSTOMER_H
