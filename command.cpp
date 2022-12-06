/* @file command.cpp
 * @brief The following code gives the implementations of the command class
 * @author Anthony Vu
 * @date 12/05/2022
 */
 
 #include "command.h"

//command constructor
Command::Command() {
	this->commandCase = DefaultCommandCase;
	this->customerID = DEFAULT_ID;
	this->fullCommand = DefaultCommandCase;
}

//copy constructor 
Command::Command(const Command& other) {
	this->commandCase = other.commandCase;
	this->customerID = other.customerID;
	this->fullCommand = other.fullCommand;
}

//destructor 
Command::~Command() {}

/* getCustomerID retrieves the customers ID
 */
int Command::getCustomerID() const {
	return this->customerID;
}

/* setCustomerID sets the customers ID
 */
void Command::setCustomerID(int ID) {
	this->customerID = ID;
}

/* getCommandType retrieves the command type
 */
CommandCase Command::getCommandType() const {
	return this->commandCase;
}

/* setCommandType sets the command type
 */
void Command::setCommandType(CommandCase in) {
	this->commandCase = in;
}

/* process proccesses the command
 */
void Command::process(Database& Datab, CustomerDatabase& cusDatab)
{
	bool flag = false;

	switch (this->commandCase) {
	case BorrowCase:
		flag = dynamic_cast<Borrow*>(this)->processBorrow(Datab, cusDatab);
		break;
	case ReturnCase:
		flag = dynamic_cast<Return*>(this)->processReturn(Datab, cusDatab);
		break;
	case HistoryCase:
		flag = dynamic_cast<History*>(this)->processHistory(cusDatab);
		break;
	case InventoryCase:
		dynamic_cast<Inventory*>(this)->processInventory(Datab);
		break;
	default:
		cerr << "Command, nothing to process" << endl;
		flag = false;
		break;
	}
	if (!flag|| this->commandCase == HistoryCase || this->commandCase == InventoryCase)
		delete this;
}

/* out sets the ostream data
 */
ostream& Command::out(ostream& out) const {
	out << (char)this->commandCase;
	return out;
}

/* operator<< prints out the command
 */ 
ostream& operator<<(ostream& stream, const Command& comm) {
	comm.out(stream);
	return stream;
}