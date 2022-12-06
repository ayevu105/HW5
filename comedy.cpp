#include "comedy.h"

//constructor MovieComedy()
Comedy::Comedy()
{
    this->movieType = MovieType::ComedyType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

//copy constructor MovieComedy
Comedy::Comedy(const Comedy& other)
{
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

//destructor
Comedy::~Comedy(){}

//getMovieType: getter to return the movie type
MovieType Comedy::getMovieType() const
{
    return this->movieType;
}

//setData: read and set the movie according to the input file
bool Comedy::setData(ifstream& stream)
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
void Comedy::print(ostream& stream) const
{
    cout << (char)this->getMovieType() << ", "<< this->getStock() << ", "
        << this->getDirector() << ", "<< this->getTitle() << ", "<< this->getYear();
}

//operator to compare movies
bool Comedy::operator<(const InventoryDatabase& other) const
{
    //compare title
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) != 0)
        return this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) < 0;

    //compare year
    return this->getYear() < dynamic_cast<const Comedy&>(other).getYear();
}

//operator
bool Comedy::operator<=(const InventoryDatabase& other) const
{
    //compare title
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) > 0)
        return false;

    //compare year
    return this->getYear() <= dynamic_cast<const Comedy&>(other).getYear();
}

//operator 
bool Comedy::operator>(const InventoryDatabase& other) const
{
    //compare title
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) != 0)
        return this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) > 0;

    //compare year
    return this->getYear() > dynamic_cast<const Comedy&>(other).getYear();
}

//operator
bool Comedy::operator>=(const InventoryDatabase& other) const
{
    //compare title
    if (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) < 0)
        return false;

    //compare year
    return this->getYear() >= dynamic_cast<const Comedy&>(other).getYear();
}

//operator
bool Comedy::operator==(const InventoryDatabase& other) const
{
    return (this->getTitle().compare(dynamic_cast<const Comedy&>(other).getTitle()) == 0)
        && (this->getYear() == dynamic_cast<const Comedy&>(other).getYear());
}

//operator
bool Comedy::operator!=(const InventoryDatabase& other) const
{
    return !(*this == dynamic_cast<const Comedy&>(other));
}

//assign constructor
InventoryDatabase& Comedy::operator=(const InventoryDatabase& other)
{
    this->movieType = dynamic_cast<const Comedy&>(other).getMovieType();
    this->stock = dynamic_cast<const Comedy&>(other).getStock();
    this->director = dynamic_cast<const Comedy&>(other).getDirector();
    this->title = dynamic_cast<const Comedy&>(other).getTitle();
    this->year = dynamic_cast<const Comedy&>(other).getYear();
    return *this;
}

//operator<< print to the system
ostream& operator<<(ostream& stream, const Comedy& movie)
{
    movie.print(stream);
    return stream;
}
