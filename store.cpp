//
// Created by tdasari on 3/7/25.
//

#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


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
    string actor;

    int current;

    string line;
    for (getline(file, line)) {
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
            getline(ss, actor, ' '); // actor until space
            getline(ss, temp, ' '); month_released = stoi(temp);
            getline(ss, temp); year_released = stoi(temp);
        }
        else if (genre == 'F' || genre == 'D') {
            // Comedy || Drama
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
        }
        else {
            cerr << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
        }
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
    while (getline(file, line)) {
        stringstream ss(line);
        int customer_id;
        string first_name, last_name;

        ss >> customer_id >> first_name >> last_name;

        // Assuming Customer is a class with a constructor that takes id, first name, and last name
        Customer customer(customer_id, first_name, last_name);
        customers.insert(customer_id, customer); // Assuming customers is a map or similar container
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

Movie Store::getMovie(char media_type, char genre, string director, string actor, string title, int month_released, int year_released) {
    if (title != "###") {
        return inventory.get(title);
    }
    // Default return?
}