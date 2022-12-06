/* @file hashtable.h
 * @brief The following code gives the declarations of the hashtable class.
 *  This class is used to create hashtables to store values and their keys in an array type structure. 
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <string>
#include "bst.h"

using namespace std;

const int TABLE_SIZE = 97;

template <typename Key, typename Val>
class HashTable {
public:
    HashTable();

    ~HashTable();

    bool insert(Key key, Val* val);

    bool retrieve(Key key, Val*& retriever) const;

    const Val* getValue(Key key) const;

    bool remove(Key key);

    void display() const;

private:
  
    BST<Val>* table[TABLE_SIZE];

    void clear();
};

//hashtable constructor
template <typename Key, typename Val>
HashTable<Key, Val>::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        this->table[i] = nullptr;
    }
}

//destructor
template <typename Key, typename Val>
HashTable<Key, Val>::~HashTable() {
    clear();
}

/* insert inserts an object which is the vlue with it corresponding key to the bucket 
 */
template <typename Key, typename Val>
bool HashTable<Key, Val>::insert(Key key, Val* val) {
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;
    if (hash < 0) {
        return false;
    }

    if (table[hash] == nullptr) {
        table[hash] = new BST<Val>();
        return table[hash]->insert(val);
    } else {
        return table[hash]->insert(val);
    }
    return false;
}

/* retrive returns the value of the key from the hashtable
 */
template <typename Key, typename Val>
bool HashTable<Key, Val>::retrieve(Key key, Val*& retriever) const {
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    if (hash < 0) {
        return false;
    }

    if (table[hash] == nullptr) {
        return false;
    } else {
        const Val tempTarget(key);
        return table[hash]->retrieve(tempTarget, retriever);
    }
    return false;
}

/*getValue retrieves the value from the table 
 */
template <typename Key, typename Val>
const Val* HashTable<Key, Val>::getValue(Key key) const {
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    if (hash < 0) {
        return nullptr;
    }

    if (table[hash] == nullptr) {
        return nullptr;
    } else {
        Val* tempRetrive = nullptr;
        const Val tempTarget(key);
        if (table[hash]->retrieve(tempTarget, tempRetrive))
            return tempRetrive;

        return nullptr;
    }
    return nullptr;
}

/* remove deletes the value of the key
 */
template <typename Key, typename Val>
bool HashTable<Key, Val>::remove(Key key) {
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    if (hash < 0) {
        return false;
    }

    if (table[hash] == nullptr) {
        return false;
    } else {
        const Val tempTarget(key);
        return table[hash]->remove(tempTarget);
    }
}

/*display displays the table
 */
template<typename Key, typename Val>
void HashTable<Key, Val>::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr)
            table[i]->display();
    }
}

/* clear is the destructor method
 */ 
template <typename Key, typename Val>
void HashTable<Key, Val>::clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[i] != nullptr) {
            this->table[i]->clear();
            delete this->table[i];
            this->table[i] = nullptr;
        }
    }
}
#endif