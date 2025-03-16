//-------------------------- movie.cpp ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Implements the `Movie` class, which serves as a base class for different movie genres.
// -------------------------------------------------------------------- 

#include "movie.h"
#include <string>
using namespace std;

// ---------- Movie Constructor -----------
// Description: Initializes a movie object with stock, director, title, and release year.  
// preconditions: `stock` is a non-negative integer.  
// `title` and `director` are valid strings.  
// year_released` is a valid four-digit year.  
// postconditions: A movie object is created with the given attributes
Movie::Movie(int stock, const string director, const string& title, int year_released) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year_released = year_released;
}

// ---------- Getters and Setters -----------
// Description: Retrieve and update various movie attributes (title, director, stock, etc.).  
// preconditions: 'set` methods must receive valid input values.  
// postconditions: The corresponding movie attribute is updated or retrieved.  
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
 * @brief Decrements the stock of the movie by one.
 * 
 * @pre The movie must have a valid stock count greater than or equal to zero.
 * @post The stock of the movie is decreased by one, or an error message is printed if the stock is zero.
 */
void Movie::decrementStock() {
    if (stock > 0) {
        stock--;
    } else {
        cout << "ERROR: Movie '" << getTitle() << "' is out of stock.\n";
    }
}

 /**
 * @brief Increments the stock of the movie by one.
 * 
 * @pre None.
 * @post The stock of the movie is increased by one.
 */
void Movie::incrementStock() {
    stock++;
}

 /**
 * @brief Displays the details of the movie.
 * 
 * @pre The movie must have a valid title, director, year, and stock.
 * @post The movie's details are printed to the console.
 */
void Movie::display() const {
    cout << "Title: " << title << ", Director: " << director << ", Year: " << year_released << ", Stock: " << stock << endl;
}

/**
 * @brief Borrows the movie by decrementing the stock.
 * 
 * @pre The movie must have stock available for borrowing.
 * @post The stock of the movie is decreased by one.
 */
void Movie::borrow() {
    decrementStock();
}

/**
 * @brief Returns the movie by incrementing the stock.
 * 
 * @pre The movie must have been borrowed before.
 * @post The stock of the movie is increased by one.
 */
void Movie::returnMovie() {
    incrementStock();
}

 /**
 * @brief Compares two movies for equality.
 * 
 * @param rhs The movie object to compare against.
 * @return bool True if the movies are equal, otherwise false.
 * @pre None.
 * @post None.
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