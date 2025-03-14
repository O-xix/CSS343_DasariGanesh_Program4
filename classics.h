//
// Created by tdasari on 2/25/25.
//

#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"
#include <string>
using namespace std;

class Classics : public Movie {
public:
    Classics(int stock, string director, string title, string major_actor_name, int release_month, int yearReleased)
        : Movie(stock, director, title, yearReleased), release_month(release_month), major_actor_name(major_actor_name) {
            setGenre('C');
        }

    void display() override;
    void borrow() override;
    void returnMovie() override;
    bool operator==(const Movie& rhs) const override;
    bool operator!=(const Movie& rhs) const override;
    bool operator<(const Movie& rhs) const override;
    bool operator>(const Movie& rhs) const override;
    bool operator<=(const Movie& rhs) const override;
    bool operator>=(const Movie& rhs) const override;

    int getReleaseMonth() const;
    void setReleaseMonth(int release_month);
    string getMajorActorName() const;
    void setMajorActorName(string major_actor_name);
private:
    int release_month;
    string major_actor_name;
};

#include "classics.cpp"

#endif // CLASSICS_H

