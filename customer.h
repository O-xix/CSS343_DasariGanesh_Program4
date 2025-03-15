//
// Created by tdasari on 3/7/25.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "transaction.h"
#include "movie.h"

using namespace std;

//class Borrow;

class Customer{
public:
    Customer(); //Default constructor
    Customer(int customer_id, string last_name, string first_name) : customer_id(customer_id), last_name(last_name), first_name(first_name) {};
    void addTransaction(Transaction* transaction); //Add a transaction the Customer has made to the transactionHistory for that Customer
    void displayHistory(); //Prints out history in chronological order as the transaction appears in the transactions file.
    vector<Transaction*>* getTransactions();
    void printName();
private:
    int customer_id; //Stores unique customer ID
    string last_name; //Stores last name of the customer
    string first_name; //Stores first name of the customer
    vector<Transaction*> transactionHistory; // Stores transaction history of the customer in the order that is in the input transaction file
};

#include "customer.cpp"


#endif //CUSTOMER_H
