//
// Created by tdasari on 2/25/25.
//

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;


class Movie {
public:
    Movie(int stock, string director, string title, int yearReleased) : stock(stock), director(director), title(title), year_released(year_released) {}; //Default constructor, assigns values to respective fields
    virtual void display(); //To display movies in their respective formats, depending on the genre
    virtual void borrow(); //To be used by the Borrow transaction
    //Would decrement stock and handle any stock decrement beyond a stock of 0 through conditionals.
    virtual void returnMovie(); //To be used by the Return transaction
    //Would decrement stock and handle any stock decrement beyond a stock of 0 through conditionals.
    bool operator==(const Movie& rhs); //Equivalancy operator overload
    bool operator!=(const Movie& rhs); //Non-equivalancy operator overload
    bool operator<(const Movie& rhs); //Less than operator overload
    bool operator>(const Movie& rhs); //Greater than operator overload
    bool operator<=(const Movie& rhs); //Less than or equal to operator overload
    bool operator>=(const Movie& rhs); //Greater than or equal to operator overload
    //All comparison operators would be used to sort, therefore would follow sorting criteria laid out for each genre

    //Getters and setters for all fields
    int getStock();
    void setStock(int stock);
    string getDirector();
    void setDirector(string director);
    string getTitle();
    void setTitle(string title);
    int getYearReleased();
    void setYearReleased(int year_released);
private:
    int stock; //Stores number of DVDs this particular movie has
    string director; //Stores name of director
    string title; //Stores title of movie
    int year_released; //Stores the year of release
};

#include "movie.cpp"

#endif //MOVIE_H
