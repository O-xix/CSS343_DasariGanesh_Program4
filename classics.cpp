//
// Created by tdasari on 2/25/25.
//

#include "classics.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * @brief Displays the details of the classics movie.
 * 
 * @pre The Classics object has been created.
 * @post Outputs the details of the classics movie to the console.
 */
void Classics::display() const {
    cout << setw(8) << left << getGenre() << setw(8) << left << 'D' << setw(35)
       << left << getTitle() << setw(22) << left << getDirector() << setw(22) << left << major_actor_name << setw(8) << left
       << release_month << setw(8) << left << getYearReleased() << setw(8) << left << getStock()
       << endl;
}

/**
 * @brief Borrows a copy of the classics movie.
 * 
 * @pre The Classics object has been created and the stock is greater than 0.
 * @post The number of copies of the classics movie in stock is decremented by 1.
 */
void Classics::borrow() {
    decrementStock();
}

/**
 * @brief Returns a copy of the classics movie.
 * 
 * @pre The Classics object has been created.
 * @post The number of copies of the classics movie in stock is incremented by 1.
 */
void Classics::returnMovie() {
    incrementStock();
}

/**
 * @brief Gets the release month of the classics movie.
 * 
 * @return int The release month of the classics movie.
 * @pre The Classics object has been created.
 * @post Returns the release month of the classics movie.
 */
int Classics::getReleaseMonth() const {
    return release_month;
}

/**
 * @brief Sets the release month of the classics movie.
 * 
 * @param releaseMonth The release month to set.
 * @pre The Classics object has been created.
 * @post The release month of the classics movie is set.
 */
void Classics::setReleaseMonth(const int releaseMonth) {
    release_month = releaseMonth;
}

/**
 * @brief Gets the major actor's name of the classics movie.
 * 
 * @return string The major actor's name of the classics movie.
 * @pre The Classics object has been created.
 * @post Returns the major actor's name of the classics movie.
 */
string Classics::getMajorActorName() const {
    return major_actor_name;
}

/**
 * @brief Sets the major actor's name of the classics movie.
 * 
 * @param majorActorName The major actor's name to set.
 * @pre The Classics object has been created.
 * @post The major actor's name of the classics movie is set.
 */
void Classics::setMajorActorName(const string majorActorName) {
    major_actor_name = majorActorName;
}

/**
 * @brief Checks if two classics movies are equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are equal, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if the movies are equal, false otherwise.
 */
bool Classics::operator==(const Movie& rhs) const {
    return (getDirector() == rhs.getDirector()) &&
           (getTitle() == rhs.getTitle()) &&
           (getYearReleased() == rhs.getYearReleased()) &&
           (major_actor_name == dynamic_cast<const Classics&>(rhs).major_actor_name) && 
           (getReleaseMonth() == dynamic_cast<const Classics&>(rhs).release_month);
}

/**
 * @brief Checks if two classics movies are not equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are not equal, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if the movies are not equal, false otherwise.
 */
bool Classics::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

/**
 * @brief Checks if this classics movie is less than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than the other movie, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if this movie is less than the other movie, false otherwise.
 */
bool Classics::operator<(const Movie& rhs) const {
    if (getYearReleased() < rhs.getYearReleased()) {
        return true;
    }
    if (getYearReleased() == rhs.getYearReleased()) {
        if (getReleaseMonth() < dynamic_cast<const Classics&>(rhs).getReleaseMonth()) {
            return true;
        } else if (getReleaseMonth() == dynamic_cast<const Classics&>(rhs).getReleaseMonth()) {
            return getMajorActorName() < dynamic_cast<const Classics&>(rhs).getMajorActorName();
        }
    }
    return false;
}

/**
 * @brief Checks if this classics movie is greater than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than the other movie, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if this movie is greater than the other movie, false otherwise.
 */
bool Classics::operator>(const Movie& rhs) const {
    return !(*this < rhs || *this == rhs);
}

/**
 * @brief Checks if this classics movie is less than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than or equal to the other movie, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if this movie is less than or equal to the other movie, false otherwise.
 */
bool Classics::operator<=(const Movie& rhs) const {
    return !(*this > rhs);
}

/**
 * @brief Checks if this classics movie is greater than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than or equal to the other movie, false otherwise.
 * @pre The Classics object has been created.
 * @post Returns true if this movie is greater than or equal to the other movie, false otherwise.
 */
bool Classics::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}

