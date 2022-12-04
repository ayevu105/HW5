/* @file borrow.h
 * @brief The following code gives the declarations of the borrow class.
 *  When a customer borrows a movie from the store this class deals with that command. 
 *  The class is also the child class of transaction.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "customer.h"
#include "hashTable.h"
#include "movie.h"
#include "movieFactory.h"
#include "transaction.h"
#include <fstream>
#include <set>

class Borrow : public Transaction {
    public:
       
        //borrow constructor
        Borrow();

        //initialized constructor
        Borrow(Movie*, int);

        //destructor
        ~Borrow();

        virtual bool setData(ifstream&);

        virtual void doTransactionCommand(const vector<Movie*>&, 
                                          const HashTable&);

      
        virtual void display() const;

        virtual char getCommand() const;

        Movie* getTitleMovie() const;

    protected:
        const char command = 'B';

    private: 
        Movie* titleMovie;
        
        int customerID;
};