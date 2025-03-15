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

// ---------- decrementStock -----------
// Description: Decreases the stock count of the movie if it is available.  
// preconditions: The movie stock is greater than zero.  
// postconditions: The stock is decremented by 1, or an error message 
// is displayed if the stock is already zero.  
void Movie::decrementStock() {
    if (stock > 0) {
        stock--;
    } else {
        cout << "ERROR: Movie '" << getTitle() << "' is out of stock.\n";
    }
}

// ---------- incrementStock -----------
// Description: Increases the stock count of the movie.  
// preconditions: None.  
// postconditions: The stock is incremented by 1.   
void Movie::incrementStock() {
    stock++;
}

// ---------- display -----------
// Description: Prints the details of the movie, including title, director, year, and stock count.  
// preconditions: None.  
// postconditions: The movie details are printed in a formatted manner.  
void Movie::display() const {
    cout << "Title: " << title << ", Director: " << director << ", Year: " << year_released << ", Stock: " << stock << endl;
}

// ---------- borrow -----------
// Description: Simulates the borrowing of a movie by decrementing its stock count.  
// preconditions: The movie must be available in stock.  
// postconditions: The stock is reduced by 1 if available. 
void Movie::borrow() {
    decrementStock();
}

// ---------- returnMovie -----------
// Description: Simulates the return of a movie by increasing its stock count.  
// preconditions: None.  
// postconditions: The stock count is increased by 1.  
void Movie::returnMovie() {
    incrementStock();
}

// ---------- Operator Overloads -----------
// Description: Comparison operators for sorting and equality checking between movies.  
// preconditions: Both movies being compared must have valid titles, 
// directors, and release years.  
// postconditions: Returns the appropriate boolean value based on the comparison criteria.  
 
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