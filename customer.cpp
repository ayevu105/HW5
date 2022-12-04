/* @file customer.cpp
 * @brief The following code gives the inmplementations of the customer class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "customer.h"
#include "transaction.h"

//customer constructor
Customer::Customer() {
    ID = 0;
    firstName = "";
    lastName = "";
}

//destructor
Customer::~Customer(){
    for (auto temp: history) {
        delete temp;
    }
}

/* getID retrieves the customer ID
 */
int Customer::getID() {
    return ID;
}

/* addTransactionHistory adds a transaction to history
 */ 
void Customer::AddTransactionHistory(Transaction* trans){
    History.push_back(trans);
}

/* displayHistroy displays the history of the item
 */
void Customer::displayHistory(){
    cout << "Customer: " << ID << " History" << endl;
    for (auto temp: history) {
        temp->display();
    }
}

/* setData sets the customers data
 */
bool Customer::setData(ifstream& fileName) {
    fileName >> ID >> lastName >> firstName;
    return (ID >= MINID && ID <= MAXID);
}

/* isBorrowed checks if the movie is being borrowed
 */
bool Customer::isBorrowed(Movie* mov) {
    int borrowed = 0;
    int notBorrowed = 0;
    for (auto temp : history) {
        if (temp->getCommand() == 'B' &&
            temp->getTitleMovie()->transactionDisplay() == 
            Mov->transactionDisplay()) {
            borrowed++;
        }
        else if (temp->getCommand() == 'R' &&
                 temp->getTitleMovie()->transactionDisplay() == 
                 Mov->transactionDisplay()) {
            notBorrowed++;
        }
    }
    return notBorrowed < borrowed;
}
