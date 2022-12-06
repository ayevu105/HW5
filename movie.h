/* @file movie.h
 * @brief The following code gives the declarations of the movie class.
 *  This class is used to control the movie object and is the parent class of Comedy, Drama, and Classic. 
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _MOVIE_H_
#define _MOVIE_H_
#include "inventorydatabase.h"

class Movie: public InventoryDatabase {

	friend ostream& operator<<(ostream& stream, const Movie& Movie);

public:

	virtual ~Movie();

	virtual string getDirector() const;

	virtual string getTitle() const;

	virtual int getYear() const;

	virtual void setDirector(string director);

	virtual void setTitle(string title);

	virtual void setYear(int year);

	virtual bool setData(ifstream& stream) = 0;

	virtual MovieType getMovieType() const = 0;

	virtual MediaType getMediaType() const;

	virtual bool operator<(const InventoryDatabase&) const = 0;

	virtual bool operator<=(const InventoryDatabase&) const = 0;

	virtual bool operator>(const InventoryDatabase&) const = 0;

	virtual bool operator>=(const InventoryDatabase&) const = 0;

	virtual bool operator==(const InventoryDatabase&) const = 0;

	virtual bool operator!=(const InventoryDatabase&) const = 0;

	virtual InventoryDatabase& operator=(const InventoryDatabase&) = 0;

protected:
	MovieType movieType;

	string director;

	string title;

	int year;

	virtual void print(ostream& stream) const = 0;
};
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#endif