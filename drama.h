#ifndef _DRAMA_H_
#define	_DRAMA_H_
#include "movie.h"

class Drama : public Movie
{
    friend ostream& operator<<(ostream&, const Drama&);

public:
    //constructor
    Drama();

    //copy constructor
    Drama(const Drama& other);

    //destructor
    virtual ~Drama();

    //getter
    virtual MovieType getMovieType() const;

    //setter
    bool setData(ifstream& stream);

    void print(ostream& stream) const;

    // arithmetic operator, sort by title and then year release
    virtual bool operator<(const InventoryDatabase&) const;
    virtual bool operator<=(const InventoryDatabase&) const;
    virtual bool operator>(const InventoryDatabase&) const;
    virtual bool operator>=(const InventoryDatabase&) const;
    virtual bool operator==(const InventoryDatabase&) const;
    virtual bool operator!=(const InventoryDatabase&) const;
    virtual InventoryDatabase& operator=(const InventoryDatabase&);
};
#endif