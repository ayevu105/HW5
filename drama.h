/* @file drama.h
 * @brief The following code gives the declarations of the drama class.
 *  This class is used to verify dramas and is the child class of movie.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Drama : public Movie {
    public: 
      //drama constructor
        Drama();

      //destructor
        ~Drama();

        string getGenre();

        void setTransactionData(ifstream&);

        bool operator==(const Movie&) const;

        bool operator<(const Movie&) const;

        string transactionDisplay() const;
    
    private:

        const string genre = "D";

        string actorFirstName;

        string actorLastName;

};