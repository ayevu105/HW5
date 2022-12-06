/* @file storemanager.h
 * @brief The following code gives the declarations of the storemanager class.
 *  This class is used to read the file from main and initilaize customer, movie, and commands.
 *  It also processes borrow or return, displays history, inventory and outputs all types of movies. 
 * @author Anthony Vu
 * @date 12/05/2022
 */


#ifndef _STOREMANAGER_H_
#define _STOREMANAGER_H_
#include <fstream>
#include "customersdatabase.h"
#include "database.h"
#include "media.h"
#include "commandtype.h"
using namespace std;

class StoreManager 
{
public:
    StoreManager();

    ~StoreManager();

    void buildCustomers(ifstream& stream);

    void buildMovies(ifstream& stream);

    void processCommands(ifstream& stream);

private:
    CustomerDatabase customerDatabase;

    Database database;
};
#endif