/* @file inventory.h
 * @brief The following code gives the declarations of the inventory class.
 *  This class shows the current state of inventory and is the child class of command
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _INVENTORY_H_
#define _INVENTORY_H_
#include "command.h"

class Inventory : public Command {

    friend ostream& operator<<(ostream&, const Inventory&);

public:

    Inventory();

    ~Inventory();

    void processInventory(Database&);
};
#endif