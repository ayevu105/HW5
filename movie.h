/* @file movie.h
 * @brief The following code gives the declarations of the movie class.
 *  This class processes the data4movies.txt file and is the pareent class 
 *  of the classic, drama and comedy classes.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Movie {
    public:
      //movie contstructor
        Movie();

       //destructor
        virtual ~Movie();

        int getStockQuantity() const;

        int getAmountBorrowed() const;

        int getInitialStock() const; 

        void tncramentStock();

        void decrementStock();

        virtual string getGenre();

        virtual bool setData(ifstream&);

        virtual void setTransactionData(ifstream&);

        virtual bool operator==(const Movie&) const;

        virtual bool operator<(const Movie&) const;

        virtual void display() const;

        virtual string transactionDisplay() const;

    protected:
        void setDataHelper(ifstream&);

        void setDirectorHelper(ifstream&);

        void setTitleHelper(ifstream&);

        int stock;

        int initialStock;

        string director;
        
        string title;

        int year;
};