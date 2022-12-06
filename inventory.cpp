/* @file inventory.cpp
 * @brief The following code gives the implementations of the inventory class
 * @author Anthony Vu
 * @date 12/05/2022
 */
#include "inventory.h"

//inventory constructor
Inventory::Inventory() {
    this->commandCase = CommandCase::InventoryCase;
}

//destructor
Inventory::~Inventory() {}

/* processInventory displays the current inventory
 */
void Inventory::processInventory(Database& Datab) {
    cout << "Inventory:" << endl;
    Datab.display();
}

/* operator<< prints the command inventory data 
 */
ostream& operator<<(ostream& stream, const Inventory& command) {
    stream << command.commandCase;
    return stream;
}