//
// Created by tdasari on 3/7/25.
//

#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
using namespace std;

class Store{
public:
    void initInventory(const string& filename);
        //Read movie file using fstream
        //Create movie objects through constructors and if conditionals to ascertain movie genre
        //Store in inventory and sorts movies using operator overloads
    void initCustomers(const string& filename);
        //Read customer file using fstream
        //Create customer objects through constructors
        //Store in HashMap<int, Customer> customers
    void processCommands(const string& filename);
        //Read command file using fstream
        //create transaction objects using constructors
        //store in commands_from_file
        //translate from string data to Transaction objects
        //execute all transactions
    void addMovie(Movie* movie);
        //If movie exists, increase stock
        //Else, add to inventory and sorted movies
    void removeMovie(const string& title);
        //Remove from inventory and sorted movies
        //May destroy it if it ends up being dynamically allocated
    void displayInventory();
        //Print all movies in sorted order, assuming that they are already sorted in sortedMovies
private:
    HashMap<int, Customer> customers; //Enables fast lookup of customers by ID
    HashMap<string, Movie*> inventory; //Enables fast lookup of movies by title
    vector<Movie> sortedMovies; //Stores movies in required sorted order
    vector<string> commands_from_file; //Stores command inputs to translate into Action objects
    vector<Transaction> transactions; //Stores actions for processing individuals
}




#endif //STORE_H
