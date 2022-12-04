/* @file comedy.h
 * @brief The following code gives the declarations of the comedy class.
 *  This class is used to verify comedies and is the child class of movie.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Comedy : public Movie {
    public: 

      //comedy constructor
        Comedy();

      //intialized constructor
        Comedy(int, const string&, const string&, int);

      //destructor
        ~Comedy();

        string getGenre();

        void setTransactionData(ifstream&);

        bool operator==(const Movie&) const;

        bool operator<(const Movie&) const;

        string transactionDisplay() const;
    
    private:
        const string Genre = "F";

        string ActorFirstName;

        string ActorLastName;

};