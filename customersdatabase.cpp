/* @file customersdatabase.cpp
 * @brief The following code gives the inmplementations of the customersdatabase class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "customersdatabase.h"

//customersdatabase constructor
CustomerDatabase::CustomerDatabase() {}

//destructor
CustomerDatabase::~CustomerDatabase() {}

/*insertCustomer inserts the customer into the system
 */
bool CustomerDatabase::insertCustomer(Customer* customer) {
	return collection.insert(customer->getId(), customer);
}

/* retrieveCustomer retrieves a specific customer in the system
 */
bool CustomerDatabase::retrieveCustomer(const int& id, Customer*& retriever) const {
	return collection.retrieve(id, retriever);
}

/* removeCustomerByID removes the customer from the system by ID
 */
bool CustomerDatabase::removeCustomerByID(const int& id) {
	return collection.remove(id);
}

/*getACustomer finds the customer using their ID
 */
const Customer* CustomerDatabase::getACustomer(const int& id) const {
	return collection.getValue(id);
}

/* display displays a list of customers to the system
 */
void CustomerDatabase::display() const {
	collection.display();
}