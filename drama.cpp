/* @file drama.cpp
 * @brief The following code gives the implementations of the drama class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "drama.h"

//drama constructor
Drama::Drama() {
    this->movieType = MovieType::DramaType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

//copy constructor
Drama::Drama(const Drama& other) {
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

//destructor
Drama::~Drama() {}

/* getMovieType retrieves the movie type
 */
MovieType Drama::getMovieType() const {
    return this->movieType;
}

/* setData reads ands stores the movie into the system 
 */
bool Drama::setData(ifstream& stream) {
    stream.ignore();
    stream >> this->stock;

    stream.ignore();
    getline(stream >> ws, this->director, ',');

    stream.ignore();
    getline(stream >> ws, this->title, ',');

    stream.ignore();
    string toYear;
    
    getline(stream >> ws, toYear, '\n');
    stringstream ss;
    ss << toYear;
    ss >> this->year;
    return true;
}

/* print prints the movie information to the system
 */
void Drama::print(ostream& stream) const {
    cout << (char)this->getMovieType() << ", " << this->getStock() << ", "
        << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear();
}

/* operator< sorts by director then title
 */
bool Drama::operator<(const InventoryDatabase& other) const {
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) != 0) {
        return this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) < 0;
    }

    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) != 0) {
        return this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) < 0;
    }
    return false;
}

/* operator<= sorts by director then title
 */
bool Drama::operator<=(const InventoryDatabase& other) const {
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) > 0) {
        return false;
    }

    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) > 0) {
        return false;
    }
    return true;
}

/* operator> sorts by director then title
 */
bool Drama::operator>(const InventoryDatabase& other) const {
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) != 0) {
        return this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) > 0;
    }

    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) != 0) {
        return this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) > 0;
    }
    return false;
}

/* operator>= sorts by director then title
 */
bool Drama::operator>=(const InventoryDatabase& other) const {
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) < 0) {
        return false;
    }

    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) < 0) {
        return false;
    }
    return true;
}

/* operator== sorts by director then title
 */
bool Drama::operator==(const InventoryDatabase& other) const {
    if ((this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) == 0)
        && (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) == 0)
        && (this->getYear() == dynamic_cast<const Drama&>(other).getYear())) { 
        return true;
    }
    return false;
}

/* operator!= compares the movies
 */
bool Drama::operator!=(const InventoryDatabase& other) const {
    return !(*this == dynamic_cast<const Drama&>(other));
}

/* operator= assigns the movie
 */
InventoryDatabase& Drama::operator=(const InventoryDatabase& other) {
    this->movieType = dynamic_cast<const Drama&>(other).getMovieType();
    this->stock = dynamic_cast<const Drama&>(other).getStock();
    this->director = dynamic_cast<const Drama&>(other).getDirector();
    this->title = dynamic_cast<const Drama&>(other).getTitle();
    this->year = dynamic_cast<const Drama&>(other).getYear();
    return *this;
}

/* operator<< prints to the system operator
 */
ostream& operator<<(ostream& stream, const Drama& movie) {
    movie.print(stream);
    return stream;
}
