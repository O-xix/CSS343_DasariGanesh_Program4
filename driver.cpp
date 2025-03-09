//
// Created by tdasari on 3/6/25.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


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
    ifstream movieFile;
    ifstream customerFile;
    ifstream commandsFile;
    movieFile.open("data4movies.txt");
    customerFile.open("data4customers.txt");
    commandsFile.open("data4commands.txt");




}