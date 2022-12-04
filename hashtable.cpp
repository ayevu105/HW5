/* @file hashtable.cpp
 * @brief The following code gives the inmplementations of the hashtable class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "customer.h"
#include "hashTable.h"

HashTable::HashTable() {
    numOfKeys = 0;
    for (int I = 0; I < MAXENTRIES; I++) { 
        Table[I] = nullptr;
    }
}

HashTable::~HashTable() {
    clear();
}

/* hash creates a hash and returns an int of that hash
 */
int HashTable::hash(int cstmr) const {
  return cstmr - 1000;
}

/* add adds items in the hashtable and returns true or false if successfully added
 */
bool HashTable::add(Customer* cstmr) {
    if (cstmr->getID() < MINID || cstmr->getID() > MAXID) {
        return false;
    }
    if (Table[hash(cstmr->getID())] != nullptr) {
        cout << "Customer already exists" << endl;
        delete cstmr;
        return false;
    }
    Table[hash(cstmr->getID())] = cstmr;
    numOfKeys++;
    return true;
}

/* getItem retrieves an item from the hashtable and returns the item at that index
 * @param int type of key
 */
Customer* HashTable::getItem(int cstmr) const {
    if (cstmr < MINID || cstmr > MAXID) {
        return nullptr;
    }
    return Table[hash(cstmr)];
}

/* clear clears the hashtable
 */
void HashTable::clear() {
    for (auto temp : Table) {
        delete temp;
    }
    HashTable();
}