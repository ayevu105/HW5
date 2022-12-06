/* @file media.h
 * @brief The following code gives the declarations of the media class.
 *  This class is used to build a DVDMovie object to store in the hashtable. 
 * @author Anthony Vu
 * @date 12/05/2022
 */
#ifndef _MEDIA_H_
#define _MEDIA_H_
#include "genre.h"

class Media {
public:
	static InventoryDatabase* buildDVDMovie(ifstream& stream);
};
#endif