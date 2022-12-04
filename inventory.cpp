/* @file inventory.cpp
 * @brief The following code gives the inmplementations of the inventory class
 * @author Anthony Vu
 * @date 12/05/2022
 */
 
#include "inventory.h"

//inventory constructor
Inventory::Inventory() {}

//inventory destructor
Inventory::~Inventory() {}

/* setData sets the data from the commands file. 
 * @param commands file
 */
bool Inventory::setData(ifstream&) {
  return true;
}

/* doTransactionCommand processes the transaction command
 */
void Inventory::doTransactionCommand(const vector<Movie*>&, const HashTable&) {
}

/* display displays the transaction
 */
void Inventory::display() const {}

/* getCommand is the getter for command
 */
char Inventory::getCommand() const {
  return command;
}

/* getTitleMovie finds the movie
 */
Movie* Inventory::getTitleMovie() const {
  return nullptr;
}