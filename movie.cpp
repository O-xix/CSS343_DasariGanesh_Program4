//
// Created by tdasari on 2/25/25.
//

#include "movie.h"
#include <string>
using namespace std;

/**
 * @brief Constructor for the Movie class. Initializes the movie details.
 * 
 * @param stock The number of copies of the movie in stock.
 * @param director The director of the movie.
 * @param title The title of the movie.
 * @param year_released The year the movie was released.
 * @pre None
 * @post The Movie object is created with the specified details.
 */
Movie::Movie(int stock, const string director, const string& title, int year_released) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year_released = year_released;
}

/**
 * @brief Gets the director of the movie.
 * 
 * @return string The director of the movie.
 * @pre The Movie object has been created.
 * @post Returns the director of the movie.
 */
string Movie::getDirector() const {
    return director;
}

/**
 * @brief Gets the title of the movie.
 * 
 * @return string The title of the movie.
 * @pre The Movie object has been created.
 * @post Returns the title of the movie.
 */
string Movie::getTitle() const {
    return title;
}

/**
 * @brief Gets the year the movie was released.
 * 
 * @return int The year the movie was released.
 * @pre The Movie object has been created.
 * @post Returns the year the movie was released.
 */
int Movie::getYearReleased() const {
    return year_released;
}

/**
 * @brief Gets the number of copies of the movie in stock.
 * 
 * @return int The number of copies of the movie in stock.
 * @pre The Movie object has been created.
 * @post Returns the number of copies of the movie in stock.
 */
int Movie::getStock() const {
    return stock;
}

/**
 * @brief Gets the genre of the movie.
 * 
 * @return char The genre of the movie.
 * @pre The Movie object has been created.
 * @post Returns the genre of the movie.
 */
char Movie::getGenre() const {
    return genre;
}

/**
 * @brief Sets the director of the movie.
 * 
 * @param director The director of the movie.
 * @pre The Movie object has been created.
 * @post The director of the movie is set.
 */
void Movie::setDirector(string director) {
    this->director = director;
}

/**
 * @brief Sets the title of the movie.
 * 
 * @param title The title of the movie.
 * @pre The Movie object has been created.
 * @post The title of the movie is set.
 */
void Movie::setTitle(string title) {
    this->title = title;
}

/**
 * @brief Sets the year the movie was released.
 * 
 * @param year_released The year the movie was released.
 * @pre The Movie object has been created.
 * @post The year the movie was released is set.
 */
void Movie::setYearReleased(int year_released) {
    this->year_released = year_released;
}

/**
 * @brief Sets the number of copies of the movie in stock.
 * 
 * @param stock The number of copies of the movie in stock.
 * @pre The Movie object has been created.
 * @post The number of copies of the movie in stock is set.
 */
void Movie::setStock(int stock) {
    this->stock = stock;
}

/**
 * @brief Sets the genre of the movie.
 * 
 * @param genre The genre of the movie.
 * @pre The Movie object has been created.
 * @post The genre of the movie is set.
 */
void Movie::setGenre(char genre) {
    this->genre = genre;
}

/**
 * @brief Decrements the number of copies of the movie in stock by 1.
 * 
 * @pre The Movie object has been created and the stock is greater than 0.
 * @post The number of copies of the movie in stock is decremented by 1.
 */
void Movie::decrementStock() {
    if (stock > 0) {
        stock--;
    } else {
        cout << "ERROR: Movie '" << getTitle() << "' is out of stock.\n";
    }
}

/**
 * @brief Increments the number of copies of the movie in stock by 1.
 * 
 * @pre The Movie object has been created.
 * @post The number of copies of the movie in stock is incremented by 1.
 */
void Movie::incrementStock() {
    stock++;
}

/**
 * @brief Displays the details of the movie.
 * 
 * @pre The Movie object has been created.
 * @post Outputs the details of the movie to the console.
 */
void Movie::display() const {
    cout << "Title: " << title << ", Director: " << director << ", Year: " << year_released << ", Stock: " << stock << endl;
}

/**
 * @brief Borrows a copy of the movie.
 * 
 * @pre The Movie object has been created and the stock is greater than 0.
 * @post The number of copies of the movie in stock is decremented by 1.
 */
void Movie::borrow() {
    decrementStock();
}

/**
 * @brief Returns a copy of the movie.
 * 
 * @pre The Movie object has been created.
 * @post The number of copies of the movie in stock is incremented by 1.
 */
void Movie::returnMovie() {
    incrementStock();
}

/**
 * @brief Checks if two movies are equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are equal, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if the movies are equal, false otherwise.
 */
bool Movie::operator==(const Movie& rhs) const {
    return title == rhs.title && director == rhs.director && year_released == rhs.year_released;
}

/**
 * @brief Checks if two movies are not equal.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if the movies are not equal, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if the movies are not equal, false otherwise.
 */
bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

/**
 * @brief Checks if this movie is less than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than the other movie, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if this movie is less than the other movie, false otherwise.
 */
bool Movie::operator<(const Movie& rhs) const {
    if (title != rhs.title) return title < rhs.title;
    if (director != rhs.director) return director < rhs.director;
    return year_released < rhs.year_released;
}

/**
 * @brief Checks if this movie is greater than another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than the other movie, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if this movie is greater than the other movie, false otherwise.
 */
bool Movie::operator>(const Movie& rhs) const {
    return rhs < *this;
}

/**
 * @brief Checks if this movie is less than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is less than or equal to the other movie, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if this movie is less than or equal to the other movie, false otherwise.
 */
bool Movie::operator<=(const Movie& rhs) const {
    return !(rhs < *this);
}

/**
 * @brief Checks if this movie is greater than or equal to another movie.
 * 
 * @param rhs The movie to compare with.
 * @return bool True if this movie is greater than or equal to the other movie, false otherwise.
 * @pre The Movie object has been created.
 * @post Returns true if this movie is greater than or equal to the other movie, false otherwise.
 */
bool Movie::operator>=(const Movie& rhs) const {
    return !(*this < rhs);
}