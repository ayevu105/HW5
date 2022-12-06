/* @file media.cpp
 * @brief The following code gives the inmplementations of the media class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "media.h"

//media constructor
InventoryDatabase* Media::buildDVDMovie(ifstream& stream) {
	return Genre::buildMovie(stream);
}
