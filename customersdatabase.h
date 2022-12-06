/* @file customerdatabase.h
 * @brief The following code gives the declarations of the customerdatabase class.
 *  This class controls and modifies the information of a customer.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _CUSTOMER_DATABASE_H_
#define _CUSTOMER_DATABASE_H_
#include "customer.h"
#include "hashtable.h"

class CustomerDatabase {
public:

    CustomerDatabase();

    ~CustomerDatabase();

    bool insertCustomer(Customer* customer);

    bool retrieveCustomer(const int& id, Customer*& retriever) const;

    bool removeCustomerByID(const int& id);

    const Customer* getACustomer(const int& id) const;

    void display() const;

private:

    HashTable<int, Customer> collection;
};
#endif