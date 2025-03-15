//
// Created by tdasari on 2/25/25.
//

#include "drama.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Borrows a copy of the drama movie.
 * 
 * @pre The Drama object has been created and the stock is greater than 0.
 * @post The number of copies of the drama movie in stock is decremented by 1.
 */
void Drama::borrow() {
    decrementStock();
}

/**
 * @brief Returns a copy of the drama movie.
 * 
 * @pre The Drama object has been created.
 * @post The number of copies of the drama movie in stock is incremented by 1.
 */
void Drama::returnMovie() {
    incrementStock();
}

/**
 * @brief Displays the details of the drama movie.
 * 
 * @pre The Drama object has been created.
 * @post Outputs the details of the drama movie to the console.
 */
void Drama::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << "D" << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(8) << left
       << getYearReleased() << setw(8) << left << getStock() << endl;
}

/**
 * @brief Checks if two drama movies are equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are equal, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if the movies are equal, false otherwise.
 */
bool Drama::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) && (getTitle() == rhs.getTitle()) && (getYearReleased() == rhs.getYearReleased()) && (getStock() == rhs.getStock());
}

/**
 * @brief Checks if two drama movies are not equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are not equal, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if the movies are not equal, false otherwise.
 */
bool Drama::operator!=(const Movie& rhs) const {
    return getDirector() != rhs.getDirector() || getTitle() != rhs.getTitle();
}

/**
 * @brief Checks if this drama movie is less than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than the other movie, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if this movie is less than the other movie, false otherwise.
 */
bool Drama::operator<(const Movie& rhs) const {
    if (getDirector() < rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() < rhs.getTitle();
    } else {
        return false;
    }
}

/**
 * @brief Checks if this drama movie is greater than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than the other movie, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if this movie is greater than the other movie, false otherwise.
 */
bool Drama::operator>(const Movie& rhs) const {
    if (getDirector() > rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() > rhs.getTitle();
    } else {
        return false;
    }
}

/**
 * @brief Checks if this drama movie is less than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than or equal to the other movie, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if this movie is less than or equal to the other movie, false otherwise.
 */
bool Drama::operator<=(const Movie& rhs) const {
    return !(*this > rhs);  
}

/**
 * @brief Checks if this drama movie is greater than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than or equal to the other movie, false otherwise.
 * @pre The Drama object has been created.
 * @post Returns true if this movie is greater than or equal to the other movie, false otherwise.
 */
bool Drama::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}