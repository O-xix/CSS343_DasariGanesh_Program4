//-------------------------- store.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 3/7/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implements the Store class that handles inventory management, 
// customer interactions, and processing movie transactions. 
// This file provides methods for initializing movie and customer 
// data, processing commands, and manipulating the store's inventory
// -------------------------------------------------------------------- 
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
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * @brief Constructor for the Store class that outputs a message when the store is created.
 * 
 * @pre None
 * @post The store object is created, and the message "FINISH: Store was created" is displayed.
 */
Store::Store() {
  cout << "FINISH: Store was created" << endl;
}

/**
 * @brief Initializes the store's inventory by reading movie data from a file and storing them based on genre.
 * 
 * @param filename The name of the file containing movie data.
 * @pre The filename points to a valid file containing movie data.
 * @post Movies are added to the store's inventory for each genre, and any invalid genres are flagged as errors.
 */
void Store::initInventory(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "File not found" << endl;
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
    Classics* classicMovie = nullptr;
    Drama* dramaMovie = nullptr;
    Comedy* comedyMovie = nullptr;
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
            classicMovie = new Classics(stock, director, title, (actor_first_name + " " + actor_last_name), month_released, year_released);
            if (inventory_for_classics.get((actor_first_name + actor_last_name + to_string(month_released) + to_string(year_released))) != nullptr) {
                cout << "ERROR: Classic movie " << title << " starring " << actor_first_name << " " << actor_last_name << " already exists" << endl;
                comedyMovie = nullptr;
                continue;
            }
            inventory_for_classics.insert((actor_first_name + actor_last_name + to_string(month_released) + to_string(year_released)), classicMovie);
            sortedClassics.push_back(classicMovie);
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
            comedyMovie = new Comedy(stock, director, title, year_released);
            movie = comedyMovie;
            if (inventory.get(title) != nullptr) {
                cout << "ERROR: Comedy movie " << title << " already exists" << endl;
                comedyMovie = nullptr;
                continue;
            }
            inventory.insert(title, movie);
            sortedComedies.push_back(comedyMovie);
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
            dramaMovie = new Drama(stock, director, title, year_released);
            movie = dramaMovie;
            if (inventory.get(title) != nullptr) {
                cout << "ERROR: Drama movie " << title << " already exists" << endl;
                dramaMovie = nullptr;
                continue;
            }
            inventory.insert(title, movie);
            sortedDramas.push_back(dramaMovie);
        }
        else {
            cout << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
            continue;
        }
        movie = nullptr;
        dramaMovie = nullptr;
        classicMovie = nullptr;
        comedyMovie = nullptr;
    }
    file.close();

    sort(sortedComedies.begin(), sortedComedies.end(), [](Comedy* a, Comedy* b) { return *a < *b; });
    sort(sortedDramas.begin(), sortedDramas.end(), [](Drama* a, Drama* b) { return *a < *b; });
    sort(sortedClassics.begin(), sortedClassics.end(), [](Classics* a, Classics* b) { return *a < *b; });

    cout << "FINISH: Inventory created and file closed" << endl;
}

/**
 * @brief Initializes the customers by reading customer data from a file and storing it in a container.
 * 
 * @param filename The name of the file containing customer data.
 * @pre The filename points to a valid file containing customer data formatted with the customer's ID, first name, and last name.
 * @post Each customer is added to the store's customer container, and any invalid data is handled appropriately.
 */
void Store::initCustomers(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "File not found" << endl;
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
        if (customers.get(customer_id) != nullptr) {
            cout << "ERROR: Customer " << customer_id << " already exists" << endl;
            customer = nullptr;
            continue;
        }
        customers.insert(customer_id, customer); // Assuming customers is a map or similar container
        customer = nullptr;
    }
    file.close();

    cout << "FINISH: Customers all received" << endl;
}

// ---------- processCommands -----------
// Description: Reads a command file and processes a series of transactions including inventory actions, customer history, 
// borrowing, and returning movies.
// preconditions: The filename points to a valid file containing a list of transaction commands (borrow, return, etc.).
// postconditions: Transactions are processed, and any invalid transactions are flagged with appropriate error messages.
void Store::processCommands(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "File not found" << endl;
        return;
    }

    // Read in all transactions
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            cout << "Empty line" << endl;
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
                cout << "ERROR: History Transaction Failed -- Customer " << customer_id << "does not exist" << endl;
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

            if (customers.get(customer_id) == nullptr) {
                cout << "ERROR: Borrow or Return Transaction Failed -- Customer " << customer_id << " does not exist" << endl;
                continue;
            }

            if (media_type != 'D') {
                cout << "ERROR: Borrow or Return Transaction Failed -- Media Type " << media_type << " does not exist" << endl;
                continue;
            }

            if (genre == 'F') {
                // Comedy
                string title;
                int year_released;
                ss.ignore(1);
                getline(ss, title, ',');
                ss.ignore(1); // Ignore the space after the comma
                ss >> year_released;
                if (command == 'B') {
                    if (inventory.get(title) == nullptr) {
                        cout << "ERROR: Borrow Transaction Failed -- Funny Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, title, year_released);
                } 
                else if (command == 'R') {
                    if (inventory.get(title) == nullptr) {
                        cout << "ERROR: Borrow Transaction Failed -- Funny Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, title, year_released);
                }
                else {
                    cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
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
                        cout << "ERROR: Borrow Transaction Failed -- Drama Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, director, title);
                } 
                else if (command == 'R') {
                    if (inventory.get(title) == nullptr) {
                        cout << "ERROR: Borrow Transaction Failed -- Drama Movie (" << title << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, director, title);
                }
                else {
                    cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
                    continue;
                }
            }
            else if (genre == 'C') {
                // Classic
                int month_released, year_released;
                string actor, actor_first_name, actor_last_name;
                ss >> month_released >> year_released >> actor_first_name >> actor_last_name;
                //ss.ignore(1); // Ignore the space after the year
                //getline(ss, actor);
                actor = actor_first_name + " " + actor_last_name;
                if (command == 'B') {
                    if (inventory_for_classics.get((actor_first_name + actor_last_name + to_string(month_released) + to_string(year_released))) == nullptr) {
                        cout << "ERROR: Borrow Transaction Failed -- Classic Movie with actor (" << actor << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Borrow(customer_id, media_type, genre, month_released, year_released, actor);
                } 
                else if (command == 'R') {
                    if (inventory_for_classics.get((actor_first_name + actor_last_name + to_string(month_released) + to_string(year_released))) == nullptr) {
                        cout << "ERROR: Borrow Transaction Failed -- Classic Movie with actor (" << actor << ") does not exist in the Inventory" << endl;
                        continue;
                    }
                    transaction = new Return(customer_id, media_type, genre, month_released, year_released, actor);
                }
                else {
                    cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
                    continue;
                }
            }
            else {
                cout << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
                continue;
            }
        }
        else {
            cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
            continue;
        }
        transactions.push_back(transaction);
        transaction = nullptr;
    }
    file.close();

    // Process all transactions
    for (Transaction* transaction : transactions) {
        transaction->process(this);
    }

    cout << "FINISH: All transactions were processed and will now be removed." << endl;

    // Clean up dynamically allocated transactions
    for (Transaction* transaction : transactions) {
        delete transaction;
    }
    transactions.clear();
}

// Following are methods used to manipulate the Store object

// ---------- addMovie -----------
// Description: Adds a movie to the store's inventory. If the movie already exists, it increases the stock count.  
// preconditions: The movie object must be dynamically allocated and contain valid data.  
// postconditions: The movie is added to the inventory, or its stock count is incremented if it already exists.  
void Store::addMovie(Movie* movie) {
    inventory.insert(movie->getTitle(), movie);
}

// ---------- removeMovie -----------
// Description: Removes a movie from the store’s inventory.  
// preconditions: The movie must exist in the inventory.  
// postconditions: The movie is removed from the inventory, and if it was dynamically allocated, it may be deallocated.  
void Store::removeMovie(const string& title) {
    inventory.remove(title);
}

// ---------- displayInventory -----------
// Description: Displays all movies in the store's inventory in sorted order.  
// preconditions: The inventory must contain at least one movie.  
// postconditions: A list of movies is printed to the console in sorted order.  
void Store::displayInventory() {
    // Display Comedies:
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Comedies:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35)
       << left << "Title" << setw(22) << left << "Director" << setw(8) << left
       << "Year" << setw(8) << left << "Stock" << endl;
    for (int i = 0; i < sortedComedies.size(); i++) {
        sortedComedies[i]->display();
    }
    // Display Dramas:
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Dramas:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35)
       << left << "Title" << setw(22) << left << "Director" << setw(8) << left
       << "Year" << setw(8) << left << "Stock" << endl;
    for (int i = 0; i < sortedDramas.size(); i++) {
        sortedDramas[i]->display();
    }
    // Display Classics:
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Classics:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35)
       << left << "Title" << setw(22) << left << "Director" << setw(22) << left << "Actor" << setw(8) << left
       << "Month" << setw(8) << left << "Year" << setw(8) << left << "Stock"
       << endl;
    for (int i = 0; i < sortedClassics.size(); i++) {
        sortedClassics[i]->display();
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

// ---------- getCustomer-----------
// Description: Retrieves a customer by their ID from the store’s customer database.  
// preconditions: The customer must exist in the database.  
// postconditions: Returns a pointer to the customer object if found; otherwise, returns nullptr.  
Customer* Store::getCustomer(int id) {
    return customers.get(id);
}

// ---------- getMovie -----------
// Description: Retrieves a movie from the store’s inventory based on its media type, genre, and identifying details.  
// preconditions: The movie must exist in the inventory, and the provided parameters must match a valid entry.  
// postconditions: Returns a pointer to the movie object if found; otherwise, returns nullptr.  
Movie* Store::getMovie(char media_type, char genre, string director, string actor, string title, int month_released, int year_released) {
    if (genre == 'C') {
        string actor_first_name, actor_last_name;
        stringstream ss(actor);
        ss >> actor_first_name >> actor_last_name;
        Movie* movie = inventory_for_classics.get((actor_first_name + actor_last_name + to_string(month_released) + to_string(year_released)));
        return movie;
    }
    if (title != "###") {
        return inventory.get(title);
    }
    // Default return?
    cout << "ERROR: getMovie(), Movie Not Found." << endl;
    return nullptr;
}