//
// Created by tdasari on 2/25/25.
//

#include "comedy.h"
#include <iostream>

using namespace std;

void Comedy::display() {
    cout << "Comedy: " << title << ", " << director << ", " << year_released << endl;
}

void Comedy::borrow() {
    if (stock > 0) {
        stock--;
        cout << "You have borrowed: " << title << endl;
    } else {
        cout << "Sorry, " << title << " is currently out of stock." << endl;
    }
}

void Comedy::returnMovie() {
    stock++;
    cout << "You have returned: " << title << endl;
}

bool Comedy::operator==(const Movie& rhs) {
    return (director == rhs.getDirector()) && (title == rhs.getTitle()) && (year_released == rhs.getYearReleased()) && (stock == rhs.getStock());
}

bool Comedy::operator!=(const Movie& rhs) {
    return !(*this == rhs);
}

bool Comedy::operator<(const Movie& rhs) {
    if (director < rhs.getDirector()) {
        return true;
    } else if (director == rhs.getDirector()) {
        return title < rhs.getTitle();
    }
    return false;
}

bool Comedy::operator>(const Movie& rhs) {
    if (director > rhs.getDirector()) {
        return true;
    } else if (director == rhs.getDirector()) {
        return title > rhs.getTitle();
    }
    return false;
}

bool Comedy::operator<=(const Movie& rhs) {
    return !(this->operator>(rhs));
}

bool Comedy::operator>=(const Movie& rhs) {
    return !(this->operator<(rhs));
}


