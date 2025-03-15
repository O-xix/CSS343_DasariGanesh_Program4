//
// Created by tdasari on 2/25/25.
//

#include "classics.h"

#include "classics.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Classics::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << 'D' << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(22) << left << major_actor_name << setw(8) << left
       << release_month << setw(8) << left << getYearReleased() << setw(8) << left << getStock()
       << endl;
}

void Classics::borrow() {
    decrementStock();
}

void Classics::returnMovie() {
    incrementStock();
}

int Classics::getReleaseMonth() const {
    return release_month;
}

void Classics::setReleaseMonth(const int releaseMonth) {
    release_month = releaseMonth;
}

string Classics::getMajorActorName() const {
    return major_actor_name;
}

void Classics::setMajorActorName(const string majorActorName) {
    major_actor_name = majorActorName;
}

bool Classics::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) &&
           (getTitle() == rhs.getTitle()) &&
           (getYearReleased() == rhs.getYearReleased()) &&
           (major_actor_name == dynamic_cast<const Classics&>(rhs).major_actor_name) && (getReleaseMonth() == dynamic_cast<const Classics&>(rhs).release_month);
}

bool Classics::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

bool Classics::operator<(const Movie& rhs) const {
    if (getYearReleased() < rhs.getYearReleased()) {
        return true;
    }
    if (getYearReleased() == rhs.getYearReleased()) {
        if (getReleaseMonth() < dynamic_cast<const Classics&>(rhs).getReleaseMonth()) {
            return true;
        } else if (getReleaseMonth() == dynamic_cast<const Classics&>(rhs).getReleaseMonth()) {
            return getMajorActorName() < dynamic_cast<const Classics&>(rhs).getMajorActorName();
        }
    }
    return false;
}

bool Classics::operator>(const Movie& rhs) const {
    return !(*this < rhs || *this == rhs);
}

bool Classics::operator<=(const Movie& rhs) const {
    return !(*this > rhs);
}

bool Classics::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}

