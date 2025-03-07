//
// Created by tdasari on 2/25/25.
//

#include "movie.h"
#include <string>
using namespace std;

Movie::Movie(int stock, string director, string title, int release_year) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->release_year = release_year;
}