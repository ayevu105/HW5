/* @file inventorydatabase.cpp
 * @brief The following code gives the inmplementations of the inventorydatabase class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "inventorydatabase.h"

//destructor
InventoryDatabase::~InventoryDatabase(){}

/* getStock retrieves the amount of stock in the inventory 
 */
int InventoryDatabase::getStock() const {
	return this->stock;
}

/* setStock sets the modified number of stock in the inveotry
 */
void InventoryDatabase::setStock(unsigned int amount) {
	this->stock = amount;
}

/* addStock increases the amount in the inventory
 */
void InventoryDatabase::addStock(unsigned int amount) {
	this->stock += amount;
}

/*reduceStock reduces the amount in the inventory 
 */
bool InventoryDatabase::reduceStock(int amount) {
	if (this->stock - amount < 0) {
		return false;
	} else {
		this->stock -= amount;
	}
	return true;
}

/* operator<< prints out the inventory 
 */
ostream& operator<<(ostream& stream, const InventoryDatabase& inven) {
	inven.print(stream);
	return stream;
}
