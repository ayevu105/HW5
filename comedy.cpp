#include "Comedy.h"

Comedy::Comedy() {}

Comedy::Comedy(int Stk, const string& Drtr, const string& Ttle, int Yea) {
    Stock = Stk;
    InitialStock = Stock;
    Director = Drtr;
    Title = Ttle;
    Year = Yea;
}

Comedy::~Comedy() {}

string Comedy::GetGenre() {
    return Genre;
}

void Comedy::SetTransactionData(ifstream& FileName) {
    Movie::SetTitleHelper(FileName);
    FileName >> Year;
}

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

bool Comedy::operator==(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Comedy&>(Movies);
    return (Genre == temp.Genre && Title == temp.Title && Year == temp.Year);
}


string Comedy::TransactionDisplay() const {
    string temp;
    temp += Genre + " " + Title + ", " + to_string(Year);
    return temp;
}