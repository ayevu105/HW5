/* @file return.h
 * @brief The following code gives the declarations of the return class.
 *  This class processes the data4movies.txt file and is the pareent class 
 *  of the classic, drama and comedy classes.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "Customer.h"
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

class Return : public Transaction {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Return();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Return();

        /**
         * Sets data from commands file
         * @param: File
         * @return: None 
         */ 
        virtual bool SetData(ifstream&);

        /**
         * Process transaction command 
         * @param: None
         * @return: None 
         */ 
        virtual void DoTransactionCommand(const vector<Movie*>&, 
                                          const HashTable&);

        /**
         * Getter for command
         * @param: None
         * @return: None 
         */ 
        virtual char GetCommand() const;

        /**
         * Displays transaction
         * @param: None
         * @return: None 
         */ 
        virtual void Display() const;

        /**
         * Finds movie
         * @param: None
         * @return: None 
         */ 
        Movie* getTitleMovie() const;

    protected:
        const char Command = 'R';

    private: 
        Movie* TitleMovie; 
        int CustomerID;
};