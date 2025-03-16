//-------------------------- drama.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This header file defines the `Drama` class, which is a 
// subclass of the `Movie` class. It represents a movie of the drama genre 
// and overrides specific methods for handling borrowing, returning, 
// displaying information, and comparing instances of drama movies.
// -------------------------------------------------------------------- 

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"


class Drama : public Movie {
public:
    Drama(int stock, string director, string title, int yearReleased): Movie(stock, director, title, yearReleased) {
        setGenre('D');
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

#include "drama.cpp"

#endif //DRAMA_H
