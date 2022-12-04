/* @file movie.cpp
 * @brief The following code gives the inmplementations of the movie class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "movie.h"

//movie constructor
Movie::Movie() {
    stock = 0;
    initialStock = 0;
    year = 0;
}

//destructor
Movie::~Movie() {}

/* getStockQuantity retrieves the number of movies in stock and returns it
 */
int Movie::getStockQuantity() const {
    return stock;
}

/* getAmountBorrowed retrieves the number of movies currently being borrowed and returns it
 */
int Movie::getAmountBorrowed() const {
    int borrowAmount = initialStock - stock;
    return borrowAmount;
}

/* getInitialStocl retrieves the stock before any movies are borrowed and returns it
 */
int Movie::getInitialStock() const {
    return initialStock;
}

/* incrementStock increases the stock if a movie is returned
 */
void Movie::incramentStock() {
    stock++;
}

/* decramentStock decreases the stock if a movie is rented
 */
void Movie::decrementStock() {
    stock--;
}

/* getGenre retrieves the genre of the movie
 */
string Movie::getGenre() {
  return string();
}

/* setData sets the data from the movie file.
 * @param movie file
 */
bool Movie::setData(ifstream& fileName) {
    string temp;
    fileName >> stock >> temp;
    setDataHelper(fileName);
    fileName >> year;
    initialStock = stock;
    return true;
}

/* setTransactionData sets the transaction data
 */
void Movie::setTransactionData(ifstream&) {}

/* operator overloading for comparison
 */
bool Movie::operator==(const Movie&) const {
  return false;
}

/* operator overloading for comparison
 */
bool Movie::operator<(const Movie&) const {
  return false;
}

// helper function for setData
void Movie::setDataHelper(ifstream& fileName) {
    setDirectorHelper(fileName);
    setTitleHelper(fileName);
}

// helper function for setDirector
void Movie::SetDirectorHelper(ifstream& fileName) {
    string temp;
    fileName >> director;
    while (director.back() == ',') { 
        fileName >> temp;
        director += " ";
        director += temp;
    }
    director.pop_back();
}

// helper function for setTitle
void Movie::setTitleHelper(ifstream& fileName) {
    string temp;
    fileName >> title;
    while (title.back() == ',') { 
        fileName >> temp;
        title += " ";
        title += temp;
    }
    title.pop_back();
}

/* display displays the movie information
 */
void Movie::display() const {
    cout << left << setw(35) << title << setw(19) << director << setw(5) <<
    year << " " << "Borrowed: " << setw(3) << getAmountBorrowed() << " " <<
    "Remaining: " << stock << endl;
}

/* transactionDisplay displays the movie information
 */
string Movie::transactionDisplay() const {
  return string();
}