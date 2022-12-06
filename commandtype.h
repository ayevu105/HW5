/* @file commandtype.h
 * @brief The following code gives the declarations of the commandtype class.
 *  This class reads the input file and creates borrow, return, show history, and
 *  show inventory as command objects. 
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _COMMANDTYPE_H_
#define _COMMANDTYPE_H_
#include <iomanip>
#include "command.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"

class CommandType {
public:

    static Command* createCommand(ifstream& stream);

private:

    static Command* createBorrow(ifstream& stream);

    static Command* createReturn(ifstream& stream);

    static Command* createHistory(ifstream& stream);

    static Command* createInventory();

    static void error(const char& cType, ifstream& stream);
};
#endif