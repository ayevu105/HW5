/* @file return.cpp
 * @brief The following code gives the implementations of the return class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "return.h"

//return constructor
Return::Return(){}

//destructor
Return::~Return(){}

/* processReturn is the processecing of the return command 
 */
bool Return::processReturn(Database& Datab, CustomerDatabase& cusDatab) {
	Customer* cusRetriever;
	if (cusDatab.retrieveCustomer(this->getCustomerID(), cusRetriever)) {
		if (this->media != nullptr) {
			InventoryDatabase* meRetriever = nullptr;
			if (Datab.retrieve(*this->media, meRetriever)) {
				if (cusRetriever->returnMedia(this->media)) {
					delete this->media;
					this->media = nullptr;

					meRetriever->addStock(1);

					cusRetriever->addHistory(this);
					return true;
				}
			} else {
				cerr << "Command, media is not in the Database:" << '\n' << "  " << this->fullCommand << endl;
			}
		} else {
			cerr << "Command, this command doesn't contain media:" << '\n' << "  " << this->fullCommand << endl;
		}
	} else {
		cerr << "Command, customer does not exist:" << '\n' << "  " << this->fullCommand << endl;
	}
	return false;
}

/* out sets out the stream data 
 */
ostream& Return::out(ostream& out) const {
	out << this->fullCommand;
	return out;
}

/* operator<< prints out the command borrow data 
 */
ostream& operator<<(ostream& stream, const Return& r) {
	r.out(stream);
	return stream;
}