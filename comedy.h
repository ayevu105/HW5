#ifndef _COMEDY_H_
#define _COMEDY_H_
#include "movie.h"

/*
MovieComedy class: creates a comedy type of movie
*/
class Comedy : public Movie
{
    friend ostream& operator<<(ostream&, const Comedy&);

public:
    //constructor
    Comedy();

    //copy constructor
    Comedy(const Comedy& other);

    //destructor
    virtual ~Comedy();

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