/* @file borroworreturn.h
 * @brief The following code gives the declarations of the borroworreturn class.
 *  When a customer borrows a movie from the store this class deals with that command. 
 *  The class is also the parent class Borrow
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _CLASSIC_H_
#define	_CLASSIC_H_
#include "movie.h"

class Classic: public Movie
{
    // operator<<
    friend ostream& operator<<(ostream&, const Classic&);

public:
    //constructor
    Classic();

    //copy constructor
    Classic(const Classic& classic);

    //destructor
    virtual ~Classic();

    //getters
    int getMonth() const;
    string getMajorActorFirst() const;
    string getMajorActorLast() const;
    virtual MovieType getMovieType() const;

    //setter
    void setMonth(int month);
    void setMajorActorFirst(string first);
    void setMajorActorLast(string last);

    //initial data from movie file
    bool setData(ifstream& stream);

    //function
    void print(ostream& stream) const;

    // arithmetic operator, sort by release date and major actor
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