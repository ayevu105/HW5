#include "drama.h"

//constructor MovieDrama()
Drama::Drama()
{
    this->movieType = MovieType::DramaType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

//copy constructor MovieDrama
Drama::Drama(const Drama& other)
{
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

//destructor
Drama::~Drama() {}

//getMovieType: getter to return the movie type
MovieType Drama::getMovieType() const
{
    return this->movieType;
}

//setData: read and set the movie according to the input file
bool Drama::setData(ifstream& stream)
{
    //set stock
    stream.ignore();
    stream >> this->stock;

    //set director
    stream.ignore();
    getline(stream >> ws, this->director, ',');

    //set title
    stream.ignore();
    getline(stream >> ws, this->title, ',');

    //set year
    stream.ignore();
    string toYear;
    getline(stream >> ws, toYear, '\n');
    stringstream ss;
    ss << toYear;
    ss >> this->year;
    return true;
}

//print method
void Drama::print(ostream& stream) const
{
    cout << (char)this->getMovieType() << ", " << this->getStock() << ", "
        << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear();
}

//operator to compare movies
bool Drama::operator<(const InventoryDatabase& other) const
{
    //compare director
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) != 0)
        return this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) < 0;

    //compare title
    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) != 0)
        return this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) < 0;

    //return false when greater
    return false;
}

//operator
bool Drama::operator<=(const InventoryDatabase& other) const
{
    //compare director
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) > 0)
        return false;

    //compare title
    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) > 0)
        return false;

    //return true when less than or equal
    return true;
}

//operator 
bool Drama::operator>(const InventoryDatabase& other) const
{
    //compare director
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) != 0)
        return this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) > 0;

    //compare title
    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) != 0)
        return this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) > 0;

    // return false when greater
    return false;
}

//operator
bool Drama::operator>=(const InventoryDatabase& other) const
{
    //director first
    if (this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) < 0)
        return false;

    //compare title
    if (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) < 0)
        return false;

    // return true when less than or equal
    return true;
}

//operator
bool Drama::operator==(const InventoryDatabase& other) const
{
    if ((this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()) == 0)
        && (this->getTitle().compare(dynamic_cast<const Drama&>(other).getTitle()) == 0)
        && (this->getYear() == dynamic_cast<const Drama&>(other).getYear()))
        return true;
    return false;
}

//operator
bool Drama::operator!=(const InventoryDatabase& other) const
{
    return !(*this == dynamic_cast<const Drama&>(other));
}

//assign constructor
InventoryDatabase& Drama::operator=(const InventoryDatabase& other)
{
    this->movieType = dynamic_cast<const Drama&>(other).getMovieType();
    this->stock = dynamic_cast<const Drama&>(other).getStock();
    this->director = dynamic_cast<const Drama&>(other).getDirector();
    this->title = dynamic_cast<const Drama&>(other).getTitle();
    this->year = dynamic_cast<const Drama&>(other).getYear();
    return *this;
}

//operator<< print to the system
ostream& operator<<(ostream& stream, const Drama& movie)
{
    movie.print(stream);
    return stream;
}
