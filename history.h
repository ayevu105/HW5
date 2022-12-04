/* @file history.h
 * @brief The following code gives the declarations of the history class.
 *  This class creates and retrieves the history of customers and is the child class of transacton.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "customer.h"
#include "transaction.h"
#include "hashTable.h"
#include "movie.h"
#include <fstream>
#include <vector>

class History : public Transaction {
    public:
      //history contructor
        History();

       //destructor
        ~History();

        virtual bool setData(ifstream&);

        virtual void doTransactionCommand(const vector<Movie*>&, 
                                          const HashTable&);

        virtual void display() const;

        virtual char getCommand() const;

        Movie* getTitleMovie() const;

    protected:
        const char command = 'H';

    private: 
        int customerID;
};