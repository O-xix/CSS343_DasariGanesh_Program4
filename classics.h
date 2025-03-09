//
// Created by tdasari on 2/25/25.
//

#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"

#include <string>
using namespace std;

class Classics : public Movie {
public:
  Classics(int stock, string director, string title, int yearReleased, int release_month, string major_actor_firstname, string major_actor_lastname) : Movie(stock, director, title, yearReleased), release_month(release_month), major_actor_firstname(major_actor_firstname), major_actor_lastname(major_actor_lastname) {};
private:
  int release_month;
  string major_actor_firstname;
  string major_actor_lastname;
};



#endif //CLASSICS_H
