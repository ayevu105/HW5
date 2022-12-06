/* @file borrow.cpp
 * @brief The following code gives the implementations of the borrow class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "borrow.h"

//borrow constructor
Borrow::Borrow(){}

//destructor
Borrow::~Borrow(){}

/* processBorrow checks the inventory and processes the borrow command
 */
bool Borrow::processBorrow(Database& Datab, CustomerDatabase& cusDatab) {
	Customer* cusRetriever;
	if (cusDatab.retrieveCustomer(this->getCustomerID(), cusRetriever)) {
		if (this->media != nullptr) {
			InventoryDatabase* meRetriever = nullptr;
			if (Datab.retrieve(*this->media, meRetriever)) {
				if (meRetriever->reduceStock(1)) {
					cusRetriever->borrowMedia(this->media);
					this->media = nullptr;
					cusRetriever->addHistory(this);
					return true;
				} else { 
					cerr << "Command, DVD is out of stock:" << '\n' << "  " << this->fullCommand << endl;
				}
			} else {
				cerr << "Command, DVD is not in the store database:" << '\n' << "  " << this->fullCommand << endl;
			}
		} else {
			cerr << "Command, this command can't operate for this type of media:" << '\n' << "  " << this->fullCommand << endl;
		}
	} else {
		cerr << "Command, customer doesn't exist:" << '\n' << "  " << this->fullCommand << endl;
	}

	return false;
}

/* out sets out the stream data 
 */
ostream& Borrow::out(ostream& out) const {
	out << this->fullCommand;
	return out;
}


/* operator<< prints out the command borrow data 
 */
ostream& operator<<(ostream& stream, const Borrow& b) {
	b.out(stream);
	return stream;
}