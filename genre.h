
/* @file drama.h
 * @brief The following code gives the declarations of the drama class.
 *  This class is used to create different types of movie objects. 
 * @author Anthony Vu
 * @date 12/05/2022
 */
#ifndef _GENRE_H_
#define _GENRE_H_
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

class Genre {
public:
	
	static Movie* buildMovie(ifstream& stream);

private:
	
	static Movie* buildComedy (ifstream& stream);

	static Movie* buildDrama(ifstream& stream);

	static Movie* buildClassic(ifstream& stream);

	static void error(const char& type, ifstream& stream);
};
#endif