//
// Created by tdasari on 3/7/25.
//

#include "store.h"
#include <fstream>
#include <iostream>
using namespace std;

Store::Store() {
    return;
}

void Store::initInventory(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "File not found" << endl;
        return;
    }
    string line;
    for (getline(file, line)) {
        // Add to inventory
    }
    file.close();
}

void Store::initCustomers(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "File not found" << endl;
        return;
    }
    string line;
    for (getline(file, line)) {
        // Add to customers
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
    string line;
    for (getline(file, line)) {
        commands_from_file.push_back(line);
    }
    file.close();
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

Customer Store::getCustomer(int id) {
    return customers.get(id);
}