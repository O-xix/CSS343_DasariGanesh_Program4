//
// Created by tdasari on 2/25/25.
//

#include "classics.h"

#include "classics.h"
#include <iostream>
using namespace std;

void Classics::display() {
    cout << "Classics: " << getTitle() << ", " << getDirector() << ", " << major_actor_name
         << ", Released in " << release_month << "/" << getYearReleased() << endl;
}

void Classics::borrow() {
    decrementStock();
}

void Classics::returnMovie() {
    incrementStock();
}

bool Classics::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) &&
           (getTitle() == rhs.getTitle()) &&
           (getYearReleased() == rhs.getYearReleased()) &&
           (major_actor_name == dynamic_cast<const Classics&>(rhs).major_actor_name);
}

bool Classics::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

bool Classics::operator<(const Movie& rhs) const {
    if (getDirector() < rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        if (getTitle() < rhs.getTitle()) {
            return true;
        } else if (getTitle() == rhs.getTitle()) {
            return release_month < dynamic_cast<const Classics&>(rhs).release_month;
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

