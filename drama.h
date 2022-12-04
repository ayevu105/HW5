#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Drama : public Movie {
    public: 
        /**
         * Standard Constructor
         * @param: None 
         * @return: None
         */
        Drama();

        /**
         * Destructor
         * @param: None 
         * @return: None
         */
        ~Drama();

        /**
         * Gets genre of movie
         * @param: None 
         * @return: None
         */ 
        string GetGenre();

        /**
         * Sets data from movie file 
         * @param: None 
         * @return: None
         */ 
        void SetTransactionData(ifstream&);

        /**
         * Operators 
         * @param: None 
         * @return: None
         */ 
        bool operator==(const Movie&) const;
        bool operator<(const Movie&) const;

        /**
         * Display information about movie
         * @param: None 
         * @return: None
         */ 
        string TransactionDisplay() const;
    
    private:
        /**
         * Private variables for Classic
         * @param: None 
         * @return: None
         */ 
        const string Genre = "D";
        string ActorFirstName;
        string ActorLastName;

};