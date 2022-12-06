/* @file customer.cpp
 * @brief The following code gives the inmplementations of the customer class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "customer.h"
#include "command.h"

//customer constructor
Customer::Customer() {
	firstName = DEFAULT_NAME;
	lastName = DEFAULT_NAME;
	id = DEFAULT_ID;
}

//constructor with customer id 
Customer::Customer(int id) {
	this->id = id; 
}

//constructor with customer id, last name and first name
Customer::Customer(int id, string lastName, string firstName) {
	this->id = id;
	this->firstName = lastName;
	this->lastName = firstName;
}

//copy constructor
Customer::Customer(const Customer& other) {
	firstName = other.firstName;
	lastName = other.lastName;
	id = other.id;
}

//destructor
Customer::~Customer() {
	for (int i = borrowing.size(); i > 0; i--) {
		if (borrowing.back()) {
			delete borrowing.back();
		}
		borrowing.pop_back();
	}

	for (int i = history.size(); i > 0; i--) {
		if (history.back()) {
			delete history.back();
		}
		history.pop_back();
	}
}

/* getID retrieves the ID
 */
int Customer::getId() const {
	return id;
}

/* getLastName retrieves the last name 
 */
string Customer::getLastName() const  {
	return lastName;
}

/* getFirstName retrieves the first name 
 */
string Customer::getFirstName() const {
	return firstName;
}

/* getHistories retrieves the history of the customer
 */
const vector<Command*> Customer::getHistories() const 
{
	return history;
}

/* setID sets the customers ID
 */
void Customer::setID(int id) {
	this->id = id;
}

/* setFirstName sets the customers first name
 */
void Customer::setFirstName(string first) {
	this->firstName = first;
}

/* setLastName sets the customers last name
 */
void Customer::setLastName(string last) {
	this->lastName = last;
}

/* setData reads and retrieves the customers information
 */
bool Customer::setData(ifstream& stream) {
	bool valid = true;
	stream >> id;
	if (stream.fail() || id < MINID || id > MAXID) {
		stream.clear();
		char temp;
		while (stream.get(temp) && temp != '\n');
		return false;
	}

	stream >> lastName >> firstName;

	if (!valid) {
		stream.clear();
		char temp;
		while (stream.get(temp) && temp != '\n');
		return false;
	}
	return valid;
}

/* borrowMedia stores the customers request
 */
void Customer::borrowMedia(InventoryDatabase* media) {
	borrowing.push_back(media);
}

/* returnMedia returns the media back into the system
 */
bool Customer::returnMedia(InventoryDatabase* target) {
	bool isReturn = false;
	for (int i = 0; i < borrowing.size() && isReturn == false; i++) {
		if (*borrowing.at(i) == *target) {
			InventoryDatabase* temp = borrowing.at(i);
			borrowing.at(i) = borrowing.at(borrowing.size() - 1);
			borrowing.at(borrowing.size() - 1) = temp;
			if (borrowing.back()) {
				delete borrowing.back();
			}
			borrowing.pop_back();
			isReturn = true;
		}
	}
	return isReturn;
}

/* addHistory adds the customers request into their history
 */
void Customer::addHistory(Command* command) {
	history.push_back(command);
}

/* operator< compares the customers ID
 */
bool Customer::operator<(const Customer& other) const {
	return id < other.id;
}

/* operator<= compares the customers ID
 */
bool Customer::operator<=(const Customer& other) const {
	return id <= other.id;
}

/* operator> compares the customers ID
 */
bool Customer::operator>(const Customer& other) const {
	return id > other.id;
}

/* operator>= compares the customers ID
 */
bool Customer::operator>=(const Customer& other) const {
	return id >= other.id;
}

/* operator== compares the customers ID
 */
bool Customer::operator==(const Customer& other) const {
	return id == other.id;
}

/* operator!= compares the customers ID
 */
bool Customer::operator!=(const Customer& other) const {
	return id != other.id;
}

/* operator<< prints out the customer ID, last name and first name
 */
ostream& operator<<(ostream& out, const Customer& customer) {
	out << customer.id
		<< " " << customer.lastName
		<< " " << customer.firstName;
	return out;
}