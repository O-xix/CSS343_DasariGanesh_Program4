//
// Created by tdasari on 2/25/25.
//

#include "drama.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Drama::borrow() {
    decrementStock();
}

void Drama::returnMovie() {
    incrementStock();
}

void Drama::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << "D" << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(8) << left
       << getYearReleased() << setw(8) << left << getStock << endl;
}

bool Drama::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) && (getTitle() == rhs.getTitle()) && (getYearReleased() == rhs.getYearReleased()) && (getStock() == rhs.getStock());
}

bool Drama::operator!=(const Movie& rhs) const {
    return getDirector() != rhs.getDirector() || getTitle() != rhs.getTitle();
}

bool Drama::operator<(const Movie& rhs) const {
    if (getDirector() < rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() < rhs.getTitle();
    } else {
        return false;
    }
}

bool Drama::operator>(const Movie& rhs) const {
    if (getDirector() > rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() > rhs.getTitle();
    } else {
        return false;
    }
}

bool Drama::operator<=(const Movie& rhs) const {
    return !(*this > rhs);  
}

bool Drama::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}