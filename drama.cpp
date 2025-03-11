//
// Created by tdasari on 2/25/25.
//

#include "drama.h"

void Drama::borrow() {
    stock--;
}

void Drama::returnMovie() {
    stock++;
}

void Drama::display() {
    cout << "Drama: " << title << ", " << director << ", " << year_released << endl;
}

bool Drama::operator==(const Movie& rhs) {
    return (director == rhs.getDirector()) && (title == rhs.getTitle()) && (year_released == rhs.getYearReleased()) && (stock == rhs.getStock());
}

bool Drama::operator!=(const Movie& rhs) {
    return director != rhs.getDirector() || title != rhs.getTitle();
}

bool Drama::operator<(const Movie& rhs) {
    if (director < rhs.getDirector()) {
        return true;
    } else if (director == rhs.getDirector()) {
        return title < rhs.getTitle();
    } else {
        return false;
    }
}

bool Drama::operator>(const Movie& rhs) {
    if (director > rhs.getDirector()) {
        return true;
    } else if (director == rhs.getDirector()) {
        return title > rhs.getTitle();
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