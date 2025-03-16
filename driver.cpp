//-------------------------- driver.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This program simulates the operation of a store that manages 
// movie rentals, customer transactions, and command processing. The program 
// initializes the store's inventory, customer data, 
// and processes the given commands sequentially.
// -------------------------------------------------------------------- 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "store.h"


// Compile command: g++ driver.cpp -o output
// Run command: ./output data4movies.txt data4customers.txt data4commands.txt
// Alternate run command (for files that don't have that naming structure): ./output <movie.txt-file> <customer.txt-file> <commands.txt-file> 


int main(int argc, char *argv[]) {
//int main(int argc, char *argv[]) {
    // Requires three files, in this order: Movies, Customers, Commands

    Store store;
    
    if (argc != 4) {
      cerr << "Usage: " << argv[0] << " <movie.txt-file> <customer.txt-file> <commands.txt-file>" << endl;
    }
    store.initInventory(argv[1]);//lol venom
    store.initCustomers(argv[2]);//hi
    store.processCommands(argv[3]);

    // Have a static way of grabbing the files
    
    // Create new Store
    //Store store;

    //"data4movies.txt", using absolute file paths here because CMAKE is horrible with understanding what's in your directory
    //store.initInventory("data4movies.txt");//lol venom
    //store.initCustomers("data4customers.txt");//hi
    //store.processCommands("data4commands.txt");


    //Testing PR

}