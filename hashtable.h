/* @file hashtable.h
 * @brief The following code gives the declarations of the hashtable class.
 *  This class is a basic hashtbale that is used for customers who have been tracked.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include <iostream>

const int MAXENTRIES = 9999;

class Customer;

class HashTable {
    public: 
      //hashtable constructor
        HashTable();

      //destructor
        ~HashTable();

        int hash(int) const;

        bool add(Customer*); 

        Customer* getItem(int) const;
 
        void clear(); 

    private: 
        Customer *Table[MAXENTRIES];

        int numOfKeys;  
};