/* @file inventorydatabase.h
 * @brief The following code gives the declarations of the inventorydatabase class.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _INVENTORYDATABASE_H_
#define _INVENTORYDATABASE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

const int DEFAULT_STOCK = 0;
const string DEFAULT_TITLE = "DEFAULT";
const string DEFAULT_PERSON = "DEFAULT";
const int DEFAULT_NUM = 0;

namespace Types {
    enum MovieType : char {
        ComedyType = 'F',
        ClassicType = 'C',
        DramaType = 'D',
        DefaultMovieType = '!'
    };

    enum MediaType : char {
        DVDMovie = 'D',
        DefaultMediaType = '!'
    };
}
using namespace Types;

class InventoryDatabase {

    friend ostream& operator<<(ostream& stream, const InventoryDatabase& inven);

public:

    virtual ~InventoryDatabase();

    virtual int getStock() const;

    virtual void setStock(unsigned int amount);

    virtual bool setData(ifstream& stream) = 0;

    virtual void addStock(unsigned int amount);

    virtual bool reduceStock(int amount);

    virtual MediaType getMediaType() const = 0;

    virtual bool operator<(const InventoryDatabase&) const = 0;

    virtual bool operator<=(const InventoryDatabase&) const = 0;

    virtual bool operator>(const InventoryDatabase&) const = 0;

    virtual bool operator>=(const InventoryDatabase&) const = 0;

    virtual bool operator==(const InventoryDatabase&) const = 0;

    virtual bool operator!=(const InventoryDatabase&) const = 0;

    virtual InventoryDatabase& operator=(const InventoryDatabase&) = 0;

protected:
    int stock;

    MediaType mediaType;

    virtual void print(ostream& stream) const = 0;
};
#include "movie.h"
#endif