//
// Created by tdasari on 2/25/25.
//

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
