//-------------------------- classics.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This header file defines the `Classics` class, which is 
// a derived class of the `Movie` class. The class represents classic 
// movies with specific attributes such as the major actor's name and 
// the release month, in addition to the common attributes inherited from 
// the `Movie` base class.
// -------------------------------------------------------------------- 

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

    void display() const override;
    void borrow() override;
    void returnMovie() override;
    bool operator==(const Movie& rhs) const override;
    bool operator!=(const Movie& rhs) const override;
    bool operator<(const Movie& rhs) const override;
    bool operator>(const Movie& rhs) const override;
    bool operator<=(const Movie& rhs) const override;
    bool operator>=(const Movie& rhs) const override;

    int getReleaseMonth() const;
    void setReleaseMonth(const int releaseMonth);
    string getMajorActorName() const;
    void setMajorActorName(const string majorActorName);
private:
    int release_month;
    string major_actor_name;
};

#include "classics.cpp"

#endif // CLASSICS_H

