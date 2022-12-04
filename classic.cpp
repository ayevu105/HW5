/* @file classic.cpp
 * @brief The following code gives the inmplementations of the classic class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "classic.h"

//classic constructor
Classic::Classic() {
    Month = 0;
}

//destructor
Classic::~Classic() {}

/* getGenre retrieves the genre of the movie.
 */
string Classic::getGenre() {
    return Genre;
}

/* setData sets the data from the movie file.
 * @param movie file
 */
bool Classic::setData(ifstream& FileName) {
    string Temp;
    FileName >> Stock >> Temp;
    Movie::SetDataHelper(FileName);
    FileName >> ActorFirstName >> ActorLastName >> Month >> Year;
    InitialStock = Stock;
    return true;
}

/* setTransactionData sets the transaction data
 */
void Classic::setTransactionData(ifstream& FileName) {
    FileName >> Month >> Year >> ActorFirstName >> Year;
}

/* operator overloading for comparison
 */
bool Classic::operator<(const Movie& Movies) const{
    const auto temp = dynamic_cast<const Classic&>(Movies);

    if (Year < temp.Year) {
        return true;
    }
    if (Year == temp.Year && Month < temp.Month) {
        return true;
    }
    if (Year == temp.Year && Month == temp.Month && 
        ActorFirstName < temp.ActorFirstName) {
        return true;
    }
    return (Year == temp.Year && Month == temp.Month && 
            ActorFirstName == temp.ActorFirstName && 
            ActorLastName < ActorFirstName);
}

/* operator overloading for comparison
 */
bool Classic::operator==(const Movie& Movies) const{
    const auto temp = dynamic_cast<const Classic&>(Movies);
    return (ActorFirstName == temp.ActorFirstName && 
            ActorLastName == temp.ActorLastName &&
            Month == temp.Month && Year == temp.Year);
}

/* display displays the movie information
 */
void Classic::display() const {
    string Actor = ActorFirstName + " " + ActorLastName;
    cout << left << setw(35) << Title << setw(19) << Director << setw(3) << 
    Month << setw(5) << Year << setw(19) << Actor << "Borrowed: " << setw(3) 
    << GetAmountBorrowed() << " " << "Remaining: " << Stock << endl;
}

/* transactionDisplay displays the movie information
 */
string Classic::transactionDisplay() const {
    auto Mon = to_string(Month);
    auto Yea = to_string(Year);
    string temp;
    temp += Genre + " " + Mon + " " + Yea + " " + ActorFirstName + " " + 
    ActorLastName;
    return temp;
}