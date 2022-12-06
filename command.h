/* @file command.h
 * @brief The following code gives the declarations of the command class.
 *  This class creates a command based on the customers request and is the parent
 *  class of BorrowOrReturn, History, and Inventory.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "customersdatabase.h"
#include "database.h"

enum CommandCase  {
    BorrowCase = 'B',
    ReturnCase = 'R',
    HistoryCase = 'H',
    InventoryCase = 'I',
    DefaultCommandCase = '!'
};

class Command {
    friend ostream& operator<<(ostream&, const Command&);

public:
 
    Command();

    Command(const Command&);

    virtual ~Command();

    int getCustomerID() const;

    CommandCase getCommandType() const;

    void setCustomerID(int ID);

    void setCommandType(CommandCase);

    virtual void process(Database&, CustomerDatabase&);

protected:
    int customerID;

    CommandCase commandCase;

    string fullCommand;
    
    virtual ostream& out(ostream&) const;
};
#include "borroworreturn.h"
#include "history.h"
#include "inventory.h"
#endif