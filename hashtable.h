
#pragma once
#include <iostream>

const int MAXENTRIES = 9999;

class Customer;

class HashTable {
    public: 
        /**
         * Standard Constructor
         * @param: None 
         * @return: None 
         */ 
        HashTable();

        /**
         * Destructor
         * @param: None 
         * @return: None 
         */ 
        ~HashTable();

        /**
         * Creates hash 
         * @param: None 
         * @return: int return of Hash  
         */ 
        int Hash(int) const;

        /**
         * Adds items into Hashtable
         * @param: None 
         * @return: true or false if successfully added or not 
         */ 
        bool Add(Customer*); 

        /**
         * Getter: Gets specific item from Hashtable
         * @param: int type of key (associated with index)
         * @return: returns the item @ that index 
         */ 
        Customer* GetItem(int) const;

        /**
         * Clears hashtable
         * @param: None 
         * @return: None 
         */ 
        void clear(); 

    private: 
        Customer *Table[MAXENTRIES];
        int NumOfKeys;  
};