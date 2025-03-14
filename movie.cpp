//
// Created by tdasari on 2/25/25.
//

#include "movie.h"
#include <string>
using namespace std;

Movie::Movie(int stock, const string director, const string& title, int year_released) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year_released = year_released;
}

string Movie::getDirector() const {
    return director;
}

string Movie::getTitle() const {
    return title;
}

int Movie::getYearReleased() const {
    return year_released;
}

int Movie::getStock() const {
    return stock;
}

char Movie::getGenre() const {
    return genre;
}

void Movie::setDirector(string director) {
    this->director = director;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setYearReleased(int year_released) {
    this->year_released = year_released;
}

void Movie::setStock(int stock) {
    this->stock = stock;
}

void Movie::setGenre(char genre) {
    this->genre = genre;
}

void Movie::decrementStock() {
    if (stock > 0) {
        stock--;
    } else {
        cout << "ERROR: Movie '" << getTitle() << "' is out of stock.\n";
    }
}

void Movie::incrementStock() {
    stock++;
}

// Define the virtual functions
void Movie::display() {
    cout << "Title: " << title << ", Director: " << director << ", Year: " << year_released << ", Stock: " << stock << endl;
}

void Movie::borrow() {
    decrementStock();
}

void Movie::returnMovie() {
    incrementStock();
}

bool Movie::operator==(const Movie& rhs) const {
    return title == rhs.title && director == rhs.director && year_released == rhs.year_released;
}

bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

bool Movie::operator<(const Movie& rhs) const {
    if (title != rhs.title) return title < rhs.title;
    if (director != rhs.director) return director < rhs.director;
    return year_released < rhs.year_released;
}

bool Movie::operator>(const Movie& rhs) const {
    return rhs < *this;
}

bool Movie::operator<=(const Movie& rhs) const {
    return !(rhs < *this);
}

bool Movie::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}