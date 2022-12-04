

#include "History.h"

History::History() {
    CustomerID = 0;
}

History::~History() {}

bool History::SetData(ifstream& FileName)
{
    FileName >> CustomerID;
    return true;
}

void History::DoTransactionCommand(const vector<Movie*>&, 
                                   const HashTable& Customers)
{
    Customer* C = Customers.GetItem(CustomerID);
    if (C) {
        C->DisplayHistory();
    }
}

void History::Display() const {}

char History::GetCommand() const
{
  return Command;
}

Movie* History::getTitleMovie() const
{
  return nullptr;
}