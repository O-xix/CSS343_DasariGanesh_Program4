//
// Created by tdasari on 3/6/25.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "store.h"


int main() {
//int main(int argc, char *argv[]) {
    // Requires three files, in this order: Movies, Customers, Commands
    /*
    if (argc != 4) {
      cerr << "Usage: " << argv[0] << " <movie.txt-file> <customer.txt-file> <commands.txt-file>" << endl;
    }
    ifstream movieFile;
    movieFile.open(argv[1]);
    ifstream customerFile;
    customerFile.open(argv[2]);
    ifstream commandsFile;
    commandsFile.open(argv[3]);
    */

    // Have a static way of grabbing the files
    
    // Create new Store
    Store store;

    //"data4movies.txt", using absolute file paths here because CMAKE is horrible with understanding what's in your directory
    store.initInventory("/home/NETID/tdasari/CSS 343/Dasari_Ganesh_Program4/data4movies.txt");//lol venom
    store.initCustomers("/home/NETID/tdasari/CSS 343/Dasari_Ganesh_Program4/data4customers.txt");//hi
    store.processCommands("/home/NETID/tdasari/CSS 343/Dasari_Ganesh_Program4/data4commands.txt");


    //Testing PR

}