//
// Created by tdasari on 2/25/25.
//

#include "borrow.h"
#include "movie.h"
using namespace std;

void Borrow::process() {
    movie.borrow();
}

void Borrow::print() {
    cout << "B " << movie.getTitle() << " " << movie.getYear() << endl;
}
