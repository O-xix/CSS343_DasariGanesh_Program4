//
// Created by tdasari on 2/25/25.
//

#include "return.h"
#include <iostream>
using namespace std;

Return::Return() {
    transaction_type = 'R';
}

void Return::process() {
    movie.returnMovie();
}

void Return::print() {
    cout << "Returned " << movie.getTitle() << " by " << movie.getDirector() << endl;
}