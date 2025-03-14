//
// Created by tdasari on 3/7/25.
//

#include "store.h"
#include "movie.h"
#include "comedy.h"
#include "classics.h"
#include "drama.h"
#include "history.h"
#include "customer.h"
#include "inventory.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Store::Store() {
  cout << "Store was created" << endl;
}

void Store::initInventory(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "File not found" << endl;
        return;
    }

    // Movie fields:
    char genre;
    int stock;
    string director;
    string title;
    int month_released;
    int year_released;
    string actor_first_name;
    string actor_last_name;

    string line;
    Movie* movie = nullptr;
    while (getline(file, line)) {
        genre = line[0];
        if (genre == 'C') {
            // Classic
            stringstream ss(line);
            string temp;
            getline(ss, temp, ','); // genre
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, temp, ','); stock = stoi(temp);
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, director, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, title, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, actor_first_name, ' '); // actor until space
            getline(ss, actor_last_name, ' '); // actor until space
            getline(ss, temp, ' '); month_released = stoi(temp);
            getline(ss, temp); year_released = stoi(temp);
            inventory_for_classics.insert((actor_first_name + actor_last_name), new Classics(stock, director, title, (actor_first_name + " " + actor_last_name), month_released, year_released));
        }
        else if (genre == 'F') {
            // Comedy
            stringstream ss(line);
            string temp;
            getline(ss, temp, ','); // genre
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, temp, ','); stock = stoi(temp);
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, director, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, title, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, temp); year_released = stoi(temp);
            movie = new Comedy(stock, director, title, year_released);
            inventory.insert(title, movie);
        }
        else if (genre == 'D') {
            // Drama
            stringstream ss(line);
            string temp;
            getline(ss, temp, ','); // genre
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, temp, ','); stock = stoi(temp);
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, director, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, title, ',');
            ss.ignore(1); // Ignore the space after the comma
            getline(ss, temp); year_released = stoi(temp);
            movie = new Drama(stock, director, title, year_released);
            inventory.insert(title, movie);
        }
        else {
            cout << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
            continue;
        }
        movie = nullptr;
    }
    file.close();
    cout << "Inventory created and file closed" << endl;
}

/*
void Store::initCustomers(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "File not found" << endl;
        return;
    }
    string line;

    Customer* customer = nullptr;
    while (getline(file, line)) {
        stringstream ss(line);
        int customer_id;
        string first_name, last_name;

        ss >> customer_id >> last_name >> first_name;

        // Assuming Customer is a class with a constructor that takes id, first name, and last name
        customer = new Customer(customer_id, last_name, first_name);
        customers.insert(customer_id, customer); // Assuming customers is a map or similar container
        customer = nullptr;
    }
    file.close();
}

void Store::processCommands(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "File not found" << endl;
        return;
    }

    // Read in all transactions
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            cerr << "Empty line" << endl;
            continue;
        }
        stringstream ss(line);
        char command;
        ss >> command;

        Transaction* transaction = nullptr;

        if (command == 'I') {
            transaction = new Inventory();
        }
        else if (command == 'H') {
            // Display customer history
            int customer_id;
            ss >> customer_id;
            if (customers.get(customer_id) == nullptr) {
                cerr << "ERROR: History Transaction Failed -- Customer " << customer_id << "does not exist" << endl;
                continue;
            }
            transaction = new History(customer_id);
        }
        else if (command == 'B' || command == 'R') {
            // Borrow or Return
            int customer_id;
            char media_type;
            char genre;
            ss >> customer_id >> media_type >> genre;

            if (genre == 'F') {
                // Comedy
                string title;
                int year_released;
                getline(ss, title, ',');
                ss.ignore(1); // Ignore the space after the comma
                ss >> year_released;
                if (command == 'B') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, title, year_released);
                } 
                else if (command == 'R') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, title, year_released);
                }
                else {
                    cerr << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
                    continue;
                }
            }
            else if (genre == 'D') {
                // Drama
                string director, title;
                getline(ss, director, ',');
                ss.ignore(1); // Ignore the space after the comma
                getline(ss, title, ',');
                if (command == 'B') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, director, title);
                } 
                else if (command == 'R') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, director, title);
                }
                else {
                    cerr << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
                    continue;
                }
            }
            else if (genre == 'C') {
                // Classic
                int month_released, year_released;
                string actor;
                ss >> month_released >> year_released;
                ss.ignore(1); // Ignore the space after the year
                getline(ss, actor);
                if (command == 'B') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, month_released, year_released, actor);
                } 
                else if (command == 'R') {
                    if (inventory.get(title) == nullptr) {
                        cerr << "ERROR: Borrow Transaction Failed -- Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, month_released, year_released, actor);
                }
                else {
                    cerr << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
                    continue;
                }
            }
        }
        else {
            cerr << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
            continue;
        }
        transactions.push_back(transaction);
    }
    file.close();

    // Process all transactions
    for (Transaction* transaction : transactions) {
        transaction->process(this);
    }

    // Clean up dynamically allocated transactions
    for (Transaction* transaction : transactions) {
        delete transaction;
    }
    transactions.clear();
}

// Following are methods used to manipulate the Store object

void Store::addMovie(Movie* movie) {
    inventory.insert(movie->getTitle(), movie);
}

void Store::removeMovie(const string& title) {
    inventory.remove(title);
}

void Store::displayInventory() {
    for (int i = 0; i < sortedMovies.size(); i++) {
        sortedMovies[i].display();
    }
}

Customer* Store::getCustomer(int id) {
    return customers.get(id);
}

Movie* Store::getMovie(char media_type, char genre, string director, string actor, string title, int month_released, int year_released) {
    if (title != "###") {
        return inventory.get(title);
    }
    if (genre == 'C') {
        return inventory.findValue(isCorrectClassicMovie());
    }
    // Default return?
}

*/