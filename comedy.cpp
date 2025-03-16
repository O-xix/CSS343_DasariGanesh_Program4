//-------------------------- comedy.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This implementation file contains the method definitions 
// for the `Comedy` class, which is a derived class of the `Movie` class.
// -------------------------------------------------------------------- 

#include "comedy.h"
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * @brief Displays the details of the comedy movie.
 * 
 * @pre The Comedy object has been created.
 * @post Outputs the details of the comedy movie to the console.
 */
void Comedy::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << "D" << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(8) << left
       << getYearReleased() << setw(8) << left << getStock() << endl;
}

/**
 * @brief Borrows a copy of the comedy movie.
 * 
 * @pre The Comedy object has been created and the stock is greater than 0.
 * @post The number of copies of the comedy movie in stock is decremented by 1.
 */
void Comedy::borrow() {
    decrementStock();
}

/**
 * @brief Returns a copy of the comedy movie.
 * 
 * @pre The Comedy object has been created.
 * @post The number of copies of the comedy movie in stock is incremented by 1.
 */
void Comedy::returnMovie() {
    incrementStock();
}

/**
 * @brief Checks if two comedy movies are equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are equal, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if the movies are equal, false otherwise.
 */
bool Comedy::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) && (getTitle() == rhs.getTitle()) && (getYearReleased() == rhs.getYearReleased()) && (getStock() == rhs.getStock());
}

/**
 * @brief Checks if two comedy movies are not equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are not equal, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if the movies are not equal, false otherwise.
 */
bool Comedy::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

/**
 * @brief Checks if this comedy movie is less than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than the other movie, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if this movie is less than the other movie, false otherwise.
 */
bool Comedy::operator<(const Movie& rhs) const {
    if (getTitle() < rhs.getTitle()) {
        return true;
    } else if (getTitle() == rhs.getTitle()) {
        return getYearReleased() < rhs.getYearReleased();
    }
    return false;
}

/**
 * @brief Checks if this comedy movie is greater than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than the other movie, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if this movie is greater than the other movie, false otherwise.
 */
bool Comedy::operator>(const Movie& rhs) const {
    if (getDirector() > rhs.getDirector()) {
        return true;
    } else if (getDirector() == rhs.getDirector()) {
        return getTitle() > rhs.getTitle();
    }
    return false;
}

/**
 * @brief Checks if this comedy movie is less than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than or equal to the other movie, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if this movie is less than or equal to the other movie, false otherwise.
 */
bool Comedy::operator<=(const Movie& rhs) const {
    return !(this->operator>(rhs));
}

/**
 * @brief Checks if this comedy movie is greater than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than or equal to the other movie, false otherwise.
 * @pre The Comedy object has been created.
 * @post Returns true if this movie is greater than or equal to the other movie, false otherwise.
 */
bool Comedy::operator>=(const Movie& rhs) const {
    return !(this->operator<(rhs));
}


