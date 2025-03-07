//
// Created by tdasari on 2/25/25.
//

#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"


class Comedy : public Movie {
    Comedy(int stock, string director, string title, int yearReleased): Movie(stock, director, title, yearReleased) {}
};



#endif //COMEDY_H
