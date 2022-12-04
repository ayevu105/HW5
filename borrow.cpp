/* @file borrow.cpp
 * @brief The following code gives the inmplementations of the borrow class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "borrow.h"

//borrow constructor
Borrow::Borrow() {
    customerID = 0;
    titleMovie = nullptr;
}

//initialized constructor
Borrow::Borrow(Movie* Mov, int ID) {
    customerID = ID;
    titleMovie = Mov; 
}

//destructor
Borrow::~Borrow() {
    delete titleMovie;
}

/* SetData sets the data from the commands file. 
 * @param commands file
 */
bool Borrow::setData(ifstream& fileName) {
    string genre;
    fileName >> customerID >> mediaType >> genre; 
    titleMovie = MovieFactory::create(genre);
    if (titleMovie == nullptr) {
        return false;
    }
    titleMovie->setTransactionData(fileName);
    return true;
}

/* doTransactionCommand processes the transaction command
 */
void Borrow::doTransactionCommand(const vector<Movie*>& mov, 
                                  const HashTable& customers) {
    Customer* tempCustomer; 
    tempCustomer = customers.GetItem(customerID);
    if (tempCustomer == nullptr) {
        cout << "Customer " << customerID << " not found!" << endl;
    }

    Movie* temp = findMovie(mov, titleMovie); 
    if(temp == nullptr) {
        cout << "Movie " + titleMovie->transactionDisplay() << 
        " not found!" <<endl;
    }

    if (tempCustomer != nullptr && temp != nullptr) {
        if (temp->getStockQuantity() > 0) {
            tempCustomer->addTransactionHistory(this);
            temp->DecrementStock();
        }
        else {
            cout << "This movie has 0 stock." << endl;
        }
    }
}

/* display displays the transaction
 */
void Borrow::display() const {
    cout << "Borrow: " << mediaType << " " << 
    titleMovie->transactionDisplay() << endl;
}

/* getCommand is the getter for command
 */
char Borrow::getCommand() const {
  return command;
}

/* getTitleMovie finds the movie
 */
Movie* Borrow::getTitleMovie() const {
  return titleMovie;
}
