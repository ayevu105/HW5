
#include "Customer.h"
#include "HashTable.h"

HashTable::HashTable() {
    NumOfKeys = 0;
    for (int I = 0; I < MAXENTRIES; I++) { 
        Table[I] = nullptr;
    }
}

HashTable::~HashTable() {
    clear();
}

bool HashTable::Add(Customer* Cstmr) {
    if (Cstmr->GetID() < MINID || Cstmr->GetID() > MAXID) {
        return false;
    }
    if (Table[Hash(Cstmr->GetID())] != nullptr) {
        cout << "Customer already exists" << endl;
        delete Cstmr;
        return false;
    }
    Table[Hash(Cstmr->GetID())] = Cstmr;
    NumOfKeys++;
    return true;
}

int HashTable::Hash(int Cstmr) const {
  return Cstmr - 1000;
}

Customer* HashTable::GetItem(int Cstmr) const {
    if (Cstmr < MINID || Cstmr > MAXID) {
        return nullptr;
    }
    return Table[Hash(Cstmr)];
}

void HashTable::clear() {
    for (auto temp : Table) {
        delete temp;
    }
    HashTable();
}