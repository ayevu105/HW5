/* @file movie.cpp
 * @brief The following code gives the inmplementations of the movie class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "movie.h"

//destructor
Movie::~Movie() {}

/* getDirector retrieves the director of the movie
 */
string Movie::getDirector() const {
    return this->director;
}

/* setDirector sets the director of the movie
 */
void Movie::setDirector(string director) {
    this->director = director;
}

/* getTitle retrieves the title of the movie
 */
string Movie::getTitle() const {
    return this->title;
}

/* setTitle sets the title of the movie
 */
void Movie::setTitle(string title) {
    this->title = title;
}

/* getYear retrieves the year of the movie 
 */
int Movie::getYear() const {
    return this->year;
}

/* setYear sets the year of the movie 
 */
void Movie::setYear(int year) {
    this->year = year;
}

/* getDVD returns the media of the movie 
 */
MediaType Movie::getMediaType() const {
    return MediaType::DVDMovie;
}

/* operator<< prints the movie data 
 */
ostream& operator<<(ostream& stream, const Movie& movie) {
    movie.print(stream);
    return stream;
}