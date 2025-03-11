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

void Store::addMovie(Movie* movie) {

}

void Store::removeMovie(const string& title) {

}

void Store::displayInventory() {

}
