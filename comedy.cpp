/* @file comedy.cpp
 * @brief The following code gives the implementations of the comedy class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "comedy.h"

//comedy constructor
Comedy::Comedy(){
    this->movieType = MovieType::ComedyType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

//copy constructor
Comedy::Comedy(const Comedy& other){
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

//destructor
Comedy::~Comedy(){}

/* getMovieType retrieves the movie type
 */
MovieType Comedy::getMovieType() const {
    return this->movieType;
}

/* setData reads ands stores the movie into the system 
 */
bool Comedy::setData(ifstream& stream) {
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
void Comedy::print(ostream& stream) const {
    cout << (char)this->getMovieType() << ", "<< this->getStock() << ", "
        << this->getDirector() << ", "<< this->getTitle() << ", "<< this->getYear();
}

/* operator< sorts by title then release date
 */
bool Comedy::operator<(const InventoryDatabase& other) const {
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) != 0) {
        return this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) < 0;
    }
    return this->getYear() < dynamic_cast<const Comedy&>(other).getYear();
}

/* operator<= sorts by title then release date
 */
bool Comedy::operator<=(const InventoryDatabase& other) const {
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) > 0) {
        return false;
    }
    return this->getYear() <= dynamic_cast<const Comedy&>(other).getYear();
}

/* operator> sorts by title then release date
 */
bool Comedy::operator>(const InventoryDatabase& other) const {
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) != 0) {
        return this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) > 0;
    }
    return this->getYear() > dynamic_cast<const Comedy&>(other).getYear();
}

/* operator>= sorts by title then release date
 */
bool Comedy::operator>=(const InventoryDatabase& other) const {
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) < 0) {
        return false;
    }
    return this->getYear() >= dynamic_cast<const Comedy&>(other).getYear();
}

/* operator== sorts by title then release date
 */
bool Comedy::operator==(const InventoryDatabase& other) const {
    return (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) == 0) 
        && (this->getYear() == dynamic_cast<const Comedy&>(other).getYear());
}

/* operator!= compares the movies
 */
bool Comedy::operator!=(const InventoryDatabase& other) const {
    return !(*this == dynamic_cast<const Comedy&>(other));
}

/* operator= assigns the movie
 */
InventoryDatabase& Comedy::operator=(const InventoryDatabase& other) {
    this->movieType = dynamic_cast<const Comedy&>(other).getMovieType();
    this->stock = dynamic_cast<const Comedy&>(other).getStock();
    this->director = dynamic_cast<const Comedy&>(other).getDirector();
    this->title = dynamic_cast<const Comedy&>(other).getTitle();
    this->year = dynamic_cast<const Comedy&>(other).getYear();
    return *this;
}

/* operator<< prints to the system operator
 */
ostream& operator<<(ostream& stream, const Comedy& movie) {
    movie.print(stream);
    return stream;
}
