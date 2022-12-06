/* @file customer.h
 * @brief The following code gives the declarations of the customer class.
 *  This class creates a new list of customers into the system
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include "inventorydatabase.h"

using namespace std;

const int MINID = 1;                    
const int MAXID = 9999;                 
const int DEFAULT_ID = 0;               
const string DEFAULT_NAME = "DEFAULT"; 

class Command;

class Customer {
    friend ostream& operator<<(ostream&, const Customer&);

public:
    Customer();

    Customer(int id);

    Customer(int id, string first, string last);

    Customer(const Customer& other);

    ~Customer();

    int getId() const;

    string getFirstName() const;

    string getLastName() const;

    const vector<Command*> getHistories() const;

    void setID(int id);

    void setFirstName(string first);

    void setLastName(string last);

    bool setData(ifstream& infile);

    void borrowMedia(InventoryDatabase* media);

    bool returnMedia(InventoryDatabase* target);

    void addHistory(Command* command);

    bool operator<(const Customer&) const;

    bool operator<=(const Customer&) const;

    bool operator>(const Customer&) const;

    bool operator>=(const Customer&) const;

    bool operator==(const Customer&) const;

    bool operator!=(const Customer&) const;

private:
    int id;                          

    string firstName;                 
         
    string lastName;                     
       
    vector<InventoryDatabase*> borrowing;   

    vector<Command*> history;              
};
#endif