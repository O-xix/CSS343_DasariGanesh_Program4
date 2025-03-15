//
// Created by tdasari on 3/6/25.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "store.h"


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