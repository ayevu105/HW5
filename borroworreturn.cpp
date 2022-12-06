/* @file borroworreturn.cpp
 * @brief The following code gives the implementations of the borroworreturn class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "borroworreturn.h"

//borroworreturn constructor
BorrowOrReturn::BorrowOrReturn() {
	this->customerID = DEFAULT_ID;
	this->mediaType = DefaultMediaType;
	this->movieType = DefaultMovieType;
	this->media = nullptr;
}

//destructor
BorrowOrReturn::~BorrowOrReturn() {
	if (this->media != nullptr) {
		delete this->media;
		this->media = nullptr;
	}
}

bool BorrowOrReturn::setData(ifstream& stream) {
	
	InventoryDatabase* aMedia = nullptr;
	char tempMedia;
	char tempMovie;
	string tempID;

	fullCommand = this->commandCase;
	fullCommand += ' ';

	stream.ignore();
	stream >> tempID;
	fullCommand += tempID;
	fullCommand += ' ';

	stringstream convert(tempID);
	convert >> this->customerID;

	if(convert.fail() || customerID < 0) {
		processError(stream, tempID, string("customer ID"));
		return false;
	}

	stream.ignore();
	stream >> tempMedia;

	fullCommand += tempMedia;
	fullCommand += ' ';

	switch (tempMedia) {
	case DVDMovie:
		this->mediaType = DVDMovie;

		stream.ignore();
		stream >> tempMovie;
		fullCommand += tempMovie;
		fullCommand += ' ';

		switch (tempMovie) {
		case ComedyType:
			processComedy(stream, aMedia);
			break;
		case ClassicType:
			processClassic(stream, aMedia);
			break;
		case DramaType:
			processDrama(stream, aMedia);
			break;
		default:
			processError(stream,string().insert(0, 1, tempMovie),string("movie type"));
			break;
		}
		break;
	default:
		processError(stream,string().insert(0, 1, tempMedia),string("media type"));
		break;
	}

	stream.clear();
	this->media = aMedia;
	bool isValid = this->media != nullptr;
	return isValid;
}

/* processComedy processes the command for movie comedy type
 */
void BorrowOrReturn::processComedy(ifstream& stream, InventoryDatabase*& aMedia) {
	this->movieType = ComedyType;
	aMedia = new Comedy();
	string tempTitle;
	int tempYear;

	stream.ignore();
	getline(stream >> ws, tempTitle, ',');
	dynamic_cast<Comedy*>(aMedia)->setTitle(tempTitle);

	stream.ignore();
	stream >> tempYear;
	dynamic_cast<Comedy*>(aMedia)->setYear(tempYear);

	fullCommand += tempTitle + ", " + to_string(tempYear);
}

/* processClassic processes the command for movie classic type
 */
void BorrowOrReturn::processClassic(ifstream& stream, InventoryDatabase*& aMedia) {
	this->movieType = ClassicType;
	aMedia = new Classic();
	string tempActorFirst;
	string tempActorLast;
	int tempMonth;
	int tempYear;

	stream.ignore();
	stream >> tempMonth;
	dynamic_cast<Classic*>(aMedia)->setMonth(tempMonth);

	stream.ignore();
	stream >> tempYear;
	dynamic_cast<Classic*>(aMedia)->setYear(tempYear);

	stream.ignore();
	stream >> tempActorFirst;
	dynamic_cast<Classic*>(aMedia)->setMajorActorFirst(tempActorFirst);

	stream.ignore();
	stream >> tempActorLast;
	dynamic_cast<Classic*>(aMedia)->setMajorActorLast(tempActorLast);

	fullCommand += to_string(tempMonth)
		+ ' ' + to_string(tempYear)
		+ ' ' + tempActorFirst
		+ ' ' + tempActorLast;
}

/* processDrama processes the command for movie drama type
 */
void BorrowOrReturn::processDrama(ifstream& stream, InventoryDatabase*& aMedia) {
	this->movieType = DramaType;
	aMedia = new Drama();
	string tempTitle;
	string tempDirector;

	stream.ignore();
	getline(stream >> ws, tempDirector, ',');
	dynamic_cast<Drama*>(aMedia)->setDirector(tempDirector);

	stream.ignore();
	getline(stream >> ws, tempTitle, ',');
	dynamic_cast<Drama*>(aMedia)->setTitle(tempTitle);

	fullCommand += tempDirector + ", " + tempTitle + ", ";
}

/*processError processes if the customer ID, media type, and movie type
 *are invalid 
 */
void BorrowOrReturn::processError(ifstream& stream,const string& error,const string& message) {
	string temp;
	stream.ignore();
	getline(stream, temp, '\n');
	this->fullCommand += temp;

	cerr << "Command, invalid " << message << " '" << error << "':"
		<< '\n' << "  " << this->fullCommand << endl;
}

/* out sets out the stream data 
 */
ostream& BorrowOrReturn::out(ostream& out) const {
	out << (char)this->commandCase;
	return out;
}

/* operator<< prints out the command borrow data 
 */
ostream& operator<<(ostream& stream, const BorrowOrReturn& command) {
	command.out(stream);
	return stream;
}