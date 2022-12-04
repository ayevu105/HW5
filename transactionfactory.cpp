

#include "TransactionFactory.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}

Transaction* TransactionFactory::create(const string& TransactionType) {
    if (TransactionType == "B") { 
        return new Borrow();
    }
    if (TransactionType == "R") { 
        return new Return();
    }
    if (TransactionType == "H") { 
        return new History();
    }
    if (TransactionType == "I") { 
        return new Inventory();
    }
    cout << "Invalid command!" << endl;
    return nullptr;
}