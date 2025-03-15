//-------------------------- movie.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: Defines the `Movie` class, which serves as a base class for different movie genres.  
// It provides essential attributes and methods for managing movie details, stock, and  
// transaction-related operations like borrowing and returning movies.  
// -------------------------------------------------------------------- 
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    Movie(int stock, const string director, const string& title, int year_released); // Default constructor, assigns values to respective fields
    virtual void display() const; // To display movies in their respective formats, depending on the genre
    virtual void borrow(); // To be used by the Borrow transaction
    virtual void returnMovie(); // To be used by the Return transaction
    virtual bool operator==(const Movie& rhs) const; // Equivalency operator overload
    virtual bool operator!=(const Movie& rhs) const; // Non-equivalency operator overload
    virtual bool operator<(const Movie& rhs) const; // Less than operator overload
    virtual bool operator>(const Movie& rhs) const; // Greater than operator overload
    virtual bool operator<=(const Movie& rhs) const; // Less than or equal to operator overload
    virtual bool operator>=(const Movie& rhs) const; // Greater than or equal to operator overload

    // Getters and setters for all fields
    int getStock() const;
    void setStock(int stock);
    string getDirector() const;
    void setDirector(string director);
    string getTitle() const;
    void setTitle(string title);
    int getYearReleased() const;
    void setYearReleased(int year_released);
    char getGenre() const;
    void setGenre(char genre);

    void decrementStock(); // Decrements stock by 1
    void incrementStock(); // Increments stock by 1
private:
    int stock; // Stores number of DVDs this particular movie has
    string director; // Stores name of director
    string title; // Stores title of movie
    int year_released; // Stores the year of release
    char genre; // Stores the genre of the movie
};

#include "movie.cpp"

#endif // MOVIE_H
