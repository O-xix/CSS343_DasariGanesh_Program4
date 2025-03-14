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

string Movie::getDirector() const{
    return director;
}

string Movie::getTitle() const{
    return title;
}

int Movie::getYearReleased() const{
    return year_released;
}

int Movie::getStock() const{
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
    if(stock > 0){
        stock--;
    }else{
        cout << "ERROR: Movie '" << getTitle() << "' is out of stock.\n";
    }
}

void Movie::incrementStock() {
    stock++;
}