//
// Created by tdasari on 2/25/25.
//

#include "comedy.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Comedy::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << "D" << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(8) << left
       << getYearReleased << setw(8) << left << getStock() << endl;
}

void Comedy::borrow() {
    decrementStock();
}

void Comedy::returnMovie() {
    incrementStock();
}

bool Comedy::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) && (getTitle() == rhs.getTitle()) && (getYearReleased() == rhs.getYearReleased()) && (getStock() == rhs.getStock());
}

bool Comedy::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

bool Comedy::operator<(const Movie& rhs) const {
    if (getTitle() < rhs.getTitle()) {
        return true;
    } else if (getTitle() == rhs.getTitle()) {
        return getYearReleased() < rhs.getYearReleased();
    }
    return false;
}

bool Comedy::operator>(const Movie& rhs) const {
    if (getDirector() > rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() > rhs.getTitle();
    }
    return false;
}

bool Comedy::operator<=(const Movie& rhs) const {
    return !(this->operator>(rhs));
}

bool Comedy::operator>=(const Movie& rhs) const {
    return !(this->operator<(rhs));
}


