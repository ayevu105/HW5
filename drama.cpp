#include "Drama.h"

Drama::Drama() {}

Drama::~Drama() {}

string Drama::GetGenre() {
    return Genre;
}

void Drama::SetTransactionData(ifstream& FileName) {
    Movie::SetDataHelper(FileName);
}

bool Drama::operator<(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Drama&>(Movies);
    if (Director < temp.Director) {
        return true;
    }
    return (Director == temp.Director && Title < temp.Title);
}

bool Drama::operator==(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Drama&>(Movies);
    return (Genre == temp.Genre && Director == temp.Director && 
            Title == temp.Title);
}


string Drama::TransactionDisplay() const {
    string temp;
    temp += Genre + " " + Director + ", " + Title;
    return temp;
}