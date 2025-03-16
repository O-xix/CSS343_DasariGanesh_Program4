//-------------------------- comedy.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This header file defines the `Comedy` class, which is a 
// derived class of the `Movie` class. It represents comedy movies and 
// overrides several virtual functions such as `display`, `borrow`, 
// `returnMovie`, and comparison operators to provide functionality 
// specific to comedy movies. The genre of comedy movies is set to 'F'.
// -------------------------------------------------------------------- 

#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"


class Comedy : public Movie {
public:
    Comedy(int stock, string director, string title, int yearReleased): Movie(stock, director, title, yearReleased) {
        setGenre('F');
    };
    void display() const override;
    void borrow() override;
    void returnMovie() override;
    bool operator==(const Movie& rhs) const override;
    bool operator!=(const Movie& rhs) const override;
    bool operator<(const Movie& rhs) const override;
    bool operator>(const Movie& rhs) const override;
    bool operator<=(const Movie& rhs) const override;
    bool operator>=(const Movie& rhs) const override;

};

#include "comedy.cpp"

#endif //COMEDY_H
