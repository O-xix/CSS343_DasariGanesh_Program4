//
// Created by tdasari on 2/25/25.
//

#include "classics.h"

#include "classics.h"
#include <iostream>
using namespace std;

void Classics::display() {
    cout << "Classics: " << title << ", " << director << ", " << major_actor_name
         << ", Released in " << release_month << "/" << year_released << endl;
}

void Classics::borrow() {
    if (stock > 0) {
        stock--;
        cout << "You have borrowed " << title << ". Enjoy watching!" << endl;
    } else {
        cout << "Sorry, " << title << " is out of stock." << endl;
    }
}

void Classics::returnMovie() {
    stock++;
    cout << "You have returned " << title << ". Thank you!" << endl;
}

bool Classics::operator==(const Movie& rhs) {
    return (director == rhs.getDirector()) &&
           (title == rhs.getTitle()) &&
           (year_released == rhs.getYearReleased()) &&
           (major_actor_name == dynamic_cast<const Classics&>(rhs).major_actor_name);
}

bool Classics::operator!=(const Movie& rhs) {
    return !(*this == rhs);
}

bool Classics::operator<(const Movie& rhs) {
    if (director < rhs.getDirector()) {
        return true;
    } else if (director == rhs.getDirector()) {
        if (title < rhs.getTitle()) {
            return true;
        } else if (title == rhs.getTitle()) {
            return release_month < dynamic_cast<const Classics&>(rhs).release_month;
        }
    }
    return false;
}

bool Classics::operator>(const Movie& rhs) {
    return !(*this < rhs || *this == rhs);
}

bool Classics::operator<=(const Movie& rhs) {
    return !(*this > rhs);
}

bool Classics::operator>=(const Movie& rhs) {
    return !(*this < rhs);
}

