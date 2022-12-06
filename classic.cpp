/* @file classic.cpp
 * @brief The following code gives the inmplementations of the classic class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "classic.h"

//classic constructor
Classic::Classic() 
{
    this->movieType = MovieType::ClassicType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->majorActorFirst = DEFAULT_PERSON;
    this->majorActorLast = DEFAULT_PERSON;
    this->month = DEFAULT_NUM;
    this->year = DEFAULT_NUM;
}

//copy constructor
Classic::Classic(const Classic& other) 
{
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->majorActorFirst = other.majorActorFirst;
    this->majorActorLast = other.majorActorLast;
    this->month = other.month;
    this->year = other.year;
}

//destructor
Classic::~Classic() {}

/* setData reads ands stores the movie into the system 
 */
bool Classic::setData(ifstream& stream) {
    stream.ignore();
    stream >> this->stock;
    stream.ignore();
    getline(stream >> ws, this->director, ',');
    stream.ignore();
    getline(stream >> ws, this->title, ',');
    stream.ignore();
    stream >> this->majorActorFirst;
    stream.ignore();
    stream >> this->majorActorLast;
    stream.ignore();
    stream >> this->month;
    stream.ignore();
    stream >> this->year;
    return true;
}

/* getMajorActorFirst retrieves the major actors first name
 */
string Classic::getMajorActorFirst() const {
    return this->majorActorFirst;
}

/* setMajorActorFirst sets the major actors first name
 */
void Classic::setMajorActorFirst(string first) {
    this->majorActorFirst = first;
}

/* getMajorActorLast retrieves the major actors last name
 */
string Classic::getMajorActorLast() const {
    return this->majorActorLast;
}

/* setMajorActorLastsets the major actors last name
 */
void Classic::setMajorActorLast(string last) {
    this->majorActorLast = last;
}

/* getMonth retrieves the month of the movie 
 */
int Classic::getMonth() const {
    return this->month;
}

/* setMonth sets the month of the movie
 */
void Classic::setMonth(int month) {
    this->month = month;
}

/* getMovieType retrieves the movie type
 */
MovieType Classic::getMovieType() const {
    return this->movieType;
}

/* operator< sorts by release date and major actor
 */
bool Classic::operator<(const InventoryDatabase& other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear()) {
        return this->getYear() < dynamic_cast<const Classic&>(other).getYear();
    }

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth()) {
        return this->getMonth() < dynamic_cast<const Classic&>(other).getMonth();
    }

    return this->getMajorActorFirst().compare(dynamic_cast<const Classic&>(other).getMajorActorFirst()) < 0;
}

/* operator<= sorts by release date and major actor
 */
bool Classic::operator<=(const InventoryDatabase& other) const {
    if (this->getYear() > dynamic_cast<const Classic&>(other).getYear()) {
        return false;
    }

    if (this->getMonth() > dynamic_cast<const Classic&>(other).getMonth()) {
        return false;
    }
    return this->getMajorActorFirst().compare(dynamic_cast<const Classic&>(other).getMajorActorFirst()) <= 0;
}

/* operator> sorts by release date and major actor
 */
bool Classic::operator>(const InventoryDatabase& other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear()) {
        return this->getYear() > dynamic_cast<const Classic&>(other).getYear();
    }

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth()) {
        return this->getMonth() > dynamic_cast<const Classic&>(other).getMonth();
    }
    return this->getMajorActorFirst().compare(dynamic_cast<const Classic&>(other).getMajorActorFirst()) > 0;
}

/* operator>= sorts by release date and major actor
 */
bool Classic::operator>=(const InventoryDatabase& other) const {
    if (this->getYear() < dynamic_cast<const Classic&>(other).getYear()) {
        return false;
    }

    if (this->getMonth() < dynamic_cast<const Classic&>(other).getMonth()) {
        return false;
    }
    return this->getMajorActorFirst().compare(dynamic_cast<const Classic&>(other).getMajorActorFirst()) >= 0;
}

/* operator== sorts by release date and major actor
 */
bool Classic::operator==(const InventoryDatabase& other) const {
    return (this->getYear() == dynamic_cast<const Classic&>(other).getYear()) && (this->getMonth() == dynamic_cast<const Classic&>(other).getMonth()
            && (this->getMajorActorFirst().compare(dynamic_cast<const Classic&>(other).getMajorActorFirst()) == 0));
}

/* operator= assigns the movie
 */
InventoryDatabase& Classic::operator=(const InventoryDatabase& other) {
    this->movieType = dynamic_cast<const Classic&>(other).getMovieType();
    this->stock = dynamic_cast<const Classic&>(other).getStock();
    this->director = dynamic_cast<const Classic&>(other).getDirector();
    this->title = dynamic_cast<const Classic&>(other).getTitle();
    this->majorActorFirst = dynamic_cast<const Classic&>(other).getMajorActorFirst();
    this->majorActorLast = dynamic_cast<const Classic&>(other).getMajorActorLast();
    this->month = dynamic_cast<const Classic&>(other).getMonth();
    this->year = dynamic_cast<const Classic&>(other).getYear();
    return *this;
}

/* operator!= compares the movies
 */
bool Classic::operator!=(const InventoryDatabase& other) const {
    return !(*this == dynamic_cast<const Classic&>(other));
}

/* print prints the movie information to the system
 */
void Classic::print(ostream& stream) const {
    cout << (char)this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", "
        << this->getTitle() << ", " << this->getMajorActorFirst() << " " << this->getMajorActorLast() << ", "
        << this->getMonth() << ", " << this->getYear();
}

/* operator<< prints to the system operator
 */
ostream& operator<<(ostream& out, const Classic& movie) {
    movie.print(out);
    return out;
}