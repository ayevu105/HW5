/* @file classic.h
 * @brief The following code gives the declarations of the classic class.
 *  This class is used to verify classics and is the child class of movie.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include "movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Classic : public Movie {
    public: 
       
       //classic constructor
        Classic();

      //destructor
        ~Classic();

        string getGenre();

        bool setData(ifstream&);

        void setTransactionData(ifstream&);

        bool operator==(const Movie&) const;
        
        bool operator<(const Movie&) const;

        void display() const;

        string transactionDisplay() const;
    
    private:
        const string Genre = "C";

        string ActorFirstName;

        string ActorLastName;

        int Month;

};