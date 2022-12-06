/* @file classic.h
 * @brief The following code gives the declarations of the classic class.
 *  This class creates a classic type
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _CLASSIC_H_
#define	_CLASSIC_H_
#include "movie.h"

class Classic: public Movie {

    friend ostream& operator<<(ostream&, const Classic&);

public:
    Classic();

    Classic(const Classic& classic);

    virtual ~Classic();

    int getMonth() const;

    string getMajorActorFirst() const;

    string getMajorActorLast() const;

    virtual MovieType getMovieType() const;

    void setMonth(int month);

    void setMajorActorFirst(string first);

    void setMajorActorLast(string last);

    bool setData(ifstream& stream);

    void print(ostream& stream) const;

    virtual bool operator<(const InventoryDatabase&) const;

    virtual bool operator<=(const InventoryDatabase&) const;

    virtual bool operator>(const InventoryDatabase&) const;

    virtual bool operator>=(const InventoryDatabase&) const;

    virtual bool operator==(const InventoryDatabase&) const;

    virtual bool operator!=(const InventoryDatabase&) const;

    virtual InventoryDatabase& operator=(const InventoryDatabase&);

private:
    string majorActorFirst;

    string majorActorLast;
    
    int month;
};
#endif