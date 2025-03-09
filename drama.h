//
// Created by tdasari on 2/25/25.
//

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"


class Drama : public Movie {
public:
    Drama(int stock, string director, string title, int yearReleased): Movie(stock, director, title, yearReleased) {};
};



#endif //DRAMA_H
