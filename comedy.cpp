/* @file comedy.cpp
 * @brief The following code gives the inmplementations of the comedy class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "comedy.h"

//comedy constructor
Comedy::Comedy() {}

//initialized constructor
Comedy::Comedy(int Stk, const string& Drtr, const string& Ttle, int Yea) {
    Stock = Stk;
    InitialStock = Stock;
    Director = Drtr;
    Title = Ttle;
    Year = Yea;
}

//destructor
Comedy::~Comedy() {}

/*getGenre retrieves the genre of the movie
 */
string Comedy::getGenre() {
    return Genre;
}

/* setData sets the data from the movie file.
 * @param movie file
 */
void Comedy::setTransactionData(ifstream& FileName) {
    Movie::setTitleHelper(FileName);
    FileName >> Year;
}

/* operator overloading for comparison
 */
bool Comedy::operator<(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Comedy&>(Movies);
    if (Title < temp.Title) {
        return true;
    }
    if (Title == temp.Title && Year < temp.Year) {
        return true;
    }
    return false;
}

/* operator overloading for comparison
 */
bool Comedy::operator==(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Comedy&>(Movies);
    return (Genre == temp.Genre && Title == temp.Title && Year == temp.Year);
}

/* transactionDisplay displays the movie information
 */
string Comedy::transactionDisplay() const {
    string temp;
    temp += Genre + " " + Title + ", " + to_string(Year);
    return temp;
}