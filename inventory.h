/* @file inventory.h
 * @brief The following code gives the declarations of the inventory class.
 *  This class creates and retrieves the inventory of customers and is the child class of transacton.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "transaction.h"
#include "hashTable.h"
#include "movie.h"
#include "transaction.h"
#include <fstream>
#include <vector>

class Inventory : public Transaction {
    public:
      //inventory constructor
        Inventory();

      //destructor
        ~Inventory();

        virtual bool setData(ifstream&);

        virtual void doTransactionCommand(const vector<Movie*>&, 
                                          const HashTable&);

        virtual char getCommand() const;

        virtual void display() const;

        Movie* getTitleMovie() const;

    protected:
        const char command = 'I';
};