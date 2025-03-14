//
// Created by tdasari on 2/25/25.
//

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"


class Drama : public Movie {
public:
    Drama(int stock, string director, string title, int yearReleased): Movie(stock, director, title, yearReleased) {
        setGenre('D');
    };
    void display() override;
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
