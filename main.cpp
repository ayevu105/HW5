/**
 * Driver for starting movie store tests
 */

#include <iostream>
#include <fstream>
#include <ostream>
#include "storemanager.h"
#include "bst.h"
using namespace std;

int main() 
{
    StoreManager StoreManager;
    ifstream customerFile("data4customers.txt");  
    ifstream movieFile("data4movies.txt");        
    ifstream commandFile("data4commands.txt");      

    StoreManager.buildCustomers(customerFile);
    StoreManager.buildMovies(movieFile);
    StoreManager.processCommands(commandFile);
    return 0;
}