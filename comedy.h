/* @file comedy.h
 * @brief The following code gives the declarations of the comedy class.
 *  This class creates a comedy type
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _COMEDY_H_
#define _COMEDY_H_
#include "movie.h"

class Comedy : public Movie {
    friend ostream& operator<<(ostream&, const Comedy&);

public:

    Comedy();

    Comedy(const Comedy& other);

    virtual ~Comedy();

    virtual MovieType getMovieType() const;

    bool setData(ifstream& stream);

    void print(ostream& stream) const;

    virtual bool operator<(const InventoryDatabase&) const;

    virtual bool operator<=(const InventoryDatabase&) const;

    virtual bool operator>(const InventoryDatabase&) const;

    virtual bool operator>=(const InventoryDatabase&) const;

    virtual bool operator==(const InventoryDatabase&) const;

    virtual bool operator!=(const InventoryDatabase&) const;
    
    virtual InventoryDatabase& operator=(const InventoryDatabase&);
};
#endif