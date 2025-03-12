//
// Created by tdasari on 2/25/25.
//

#include "borrow.h"
#include "movie.h"
using namespace std;

void Borrow::process(Store* store) {
    movie.borrow();
}

void Borrow::print(Store* store) {
    cout << "Borrowed " << store..getTitle() << " by " << movie.getDirector() << endl;
}
