/* @file history.cpp
 * @brief The following code gives the implementations of the history class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "history.h"

//history constructor
History::History() {
	this->commandCase = CommandCase::HistoryCase;
	this->customerID = DEFAULT_ID;
}

//destructor
History::~History(){}

/* setData sets the history data of the customer
 */
bool History::setData(ifstream& stream) 
{
	stream.ignore();
	stream >> this->customerID;
	if (stream.fail()) {
		cout << "Customer ID is invalid" << endl;
		stream.clear();
		stream.ignore(99, '\n');
		return false;
	}
	return true;
}

/* processHistory creates the history command
 */
bool History::processHistory(CustomerDatabase& cusDatab) {
	Customer* cusRetriver = nullptr;
	if (cusDatab.retrieveCustomer(this->getCustomerID(), cusRetriver)) {
		cout << "History of " << this->getCustomerID()
			<< " " << cusRetriver->getFirstName()
			<< " " << cusRetriver->getLastName() << ':' << endl;
		if (cusRetriver->getHistories().empty()) {
			cout << "  " << "Empty!" << endl;
		} else {
			for (int i = 0; i < cusRetriver->getHistories().size(); i++) {
				cout << "  " << *cusRetriver->getHistories().at(i) << endl;
			}
			return true;
		}
	} else {
		cerr << "Command, customer not found to show history:"
			<< '\n' << "  " << this->fullCommand << endl;
	}
	return false;
}

/* out sets out the stream data 
 */
ostream& History::out(ostream& out) const {
	out << (char)this->commandCase << " " << this->getCustomerID();
	return out;
}

/* operator<< prints out the command borrow data 
 */
ostream& operator<<(ostream& stream, const History& command) {
	command.out(stream);
	return stream;
}