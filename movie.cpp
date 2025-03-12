//
// Created by tdasari on 2/25/25.
//

#include "movie.h"
#include <string>
using namespace std;

Movie::Movie(int stock, string director, string title, int year_released) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year_released = year_released;
}

string Movie::getDirector() {
    return director;
}

string Movie::getTitle() {
    return title;
}

int Movie::getYearReleased() {
    return year_released;
}

int Movie::getStock() {
    return stock;
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

void Movie::decrementStock() {
    stock--;
}

void Movie::incrementStock() {
    stock++;
}