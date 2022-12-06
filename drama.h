/* @file drama.h
 * @brief The following code gives the declarations of the drama class.
 *  This class creates a drama type
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _DRAMA_H_
#define	_DRAMA_H_
#include "movie.h"

class Drama : public Movie {
    friend ostream& operator<<(ostream&, const Drama&);

public:
    Drama();

    Drama(const Drama& other);

    virtual ~Drama();

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