

#include "HashTable.h"
#include "Transaction.h"

Transaction::Transaction() {}

Transaction::~Transaction() {}

bool Transaction::SetData(ifstream&) {
  return false;
}

void Transaction::DoTransactionCommand(const vector<Movie*>&, 
                                       const HashTable&) {}

void Transaction::Display() const {}

char Transaction::GetCommand() const {
    return ' ';
}

Movie* Transaction::GetTitleMovie() const {
    return nullptr;
}

Movie* Transaction::findMovie(const vector<Movie*>& Mov, Movie* Target) const {
    for (auto I : Mov)
        if (*Target == *I) {
            return I;
        }
    return nullptr;
}