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
    
    virtual MovieType getMovieType() const;

    string getMajorActorFirst() const;

    void setMajorActorFirst(string first);

    string getMajorActorLast() const;

    void setMajorActorLast(string last);

    int getMonth() const;

    void setMonth(int month);

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