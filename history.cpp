/* @file history.cpp
 * @brief The following code gives the inmplementations of the history class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "history.h"

History::History() {
    customerID = 0;
}

History::~History() {}

/* setData sets the data from the commands file. 
 * @param commands file
 */
bool History::setData(ifstream& fileName)
{
    fileName >> customerID;
    return true;
}

/* doTransactionCommand processes the transaction command
 */
void History::doTransactionCommand(const vector<Movie*>&, 
                                   const HashTable& customers)
{
    Customer* c = customers.getItem(customerID);
    if (c) {
        c->displayHistory();
    }
}

/* display displays the transaction
 */
void History::display() const {}

/* getCommand is the getter for command
 */
char History::getCommand() const
{
  return command;
}

/* getTitleMovie finds the movie
 */
Movie* History::getTitleMovie() const
{
  return nullptr;
}