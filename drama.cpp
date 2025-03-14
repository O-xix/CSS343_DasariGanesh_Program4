//
// Created by tdasari on 2/25/25.
//

#include "drama.h"

void Drama::borrow() {
    decrementStock();
}

void Drama::returnMovie() {
    incrementStock();
}

void Drama::display() {
    cout << "Drama: " << getTitle() << ", " << getDirector() << ", " << getYearReleased() << endl;
}

bool Drama::operator==(const Movie& rhs) {
    return (getDirector() == rhs.getDirector()) && (getTitle() == rhs.getTitle()) && (getYearReleased() == rhs.getYearReleased()) && (getStock() == rhs.getStock());
}

bool Drama::operator!=(const Movie& rhs) {
    return getDirector() != rhs.getDirector() || getTitle() != rhs.getTitle();
}

bool Drama::operator<(const Movie& rhs) {
    if (getDirector() < rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() < rhs.getTitle();
    } else {
        return false;
    }
}

bool Drama::operator>(const Movie& rhs) {
    if (getDirector() > rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() > rhs.getTitle();
    } else {
        return false;
    }
}

bool Drama::operator<=(const Movie& rhs) {
    return !(this > rhs);  
}

bool Drama::operator>=(const Movie& rhs) {
    return !(this < rhs);
}