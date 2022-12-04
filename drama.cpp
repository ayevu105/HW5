/* @file drama.cpp
 * @brief The following code gives the inmplementations of the drama class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "drama.h"

//drama constructor
Drama::Drama() {}

//destructor
Drama::~Drama() {}

/* getGenre retrieves the genre of the movie
 */
string Drama::getGenre() {
    return genre;
}

/* setData sets the data from the movie file.
 */
void Drama::setTransactionData(ifstream& fileName) {
    Movie::setDataHelper(fileName);
}

/* operator overloading for comparison
 */
bool Drama::operator<(const Movie& movies) const {
    const auto temp = dynamic_cast<const Drama&>(movies);
    if (director < temp.director) {
        return true;
    }
    return (director == temp.director && title < temp.title);
}

/* operator overloading for comparison
 */
bool Drama::operator==(const Movie& movies) const {
    const auto temp = dynamic_cast<const Drama&>(movies);
    return (genre == temp.genre && director == temp.director && 
            title == temp.title);
}

/* transactionDisplay displays the movie information
 */
string Drama::transactionDisplay() const {
    string temp;
    temp += genre + " " + director + ", " + title;
    return temp;
}