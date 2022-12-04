/* @file customer.h
 * @brief The following code gives the declarations of the customer class.
 *  This class storees the data from the file to be used for customer accounts.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "movie.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int MINID = 1000;
const int MAXID = 9999;
class Transaction; 

class Customer { 
    public: 
        
      //customer constructor
        Customer();

      //destructor
        ~Customer();

        int getID();

        void addTransactionHistory(Transaction*);

        void displayHistory();

        bool setData(ifstream&);

        bool isBorrowed(Movie*);

    private:

        int ID;

        string lastName;

        string firstName;

        vector<Transaction*> history;
};