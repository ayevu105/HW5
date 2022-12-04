#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Classic : public Movie {
    public: 
        /**
         * Standard Constructor
         * @param: None 
         * @return: None
         */
        Classic();

        /**
         * Destructor
         * @param: None 
         * @return: None
         */
        ~Classic();

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
        bool SetData(ifstream&);
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
        void Display() const;
        string TransactionDisplay() const;
    
    private:
        /**
         * Private variables for Classic
         * @param: None 
         * @return: None
         */ 
        const string Genre = "C";
        string ActorFirstName;
        string ActorLastName;
        int Month;

};