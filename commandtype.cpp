/* @file commandtype.cpp
 * @brief The following code gives the inmplementations of the commandtype class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "commandtype.h"

/* createCommand creates the command object
 */
Command* CommandType::createCommand(ifstream& stream) {
    Command* newCommand = nullptr;
    char commandType;
    stream >> commandType;

    if (stream.fail()) {
        stream.clear();
        stream.ignore(99, '\n');
        return nullptr;
    }

    switch (commandType) {
        //borrow case
    case CommandCase::BorrowCase:
        newCommand = createBorrow(stream);
        break;

        //return case
    case CommandCase::ReturnCase:
        newCommand = createReturn(stream);
        break;

        //history case
    case CommandCase::HistoryCase:
        newCommand = createHistory(stream);
        break;

        //inventory case
    case CommandCase::InventoryCase:
        newCommand = createInventory();
        break;

        //error case
    default:
        error(commandType, stream);
        break;
    }

    return newCommand;
}

/* createBorrow creates the borrowed object
 */
Command* CommandType::createBorrow(ifstream& stream) {
    Borrow* cBorrow = new Borrow();
    cBorrow->setCommandType(CommandCase::BorrowCase);
    if (cBorrow->setData(stream)) {
        return cBorrow;
    }
    delete cBorrow;
    return nullptr;
}

/* createReturn creates the returned object
 */
Command* CommandType::createReturn(ifstream& stream) {
    Return* cReturn = new Return();
    cReturn->setCommandType(CommandCase::ReturnCase);
    if (cReturn->setData(stream)) {
        return cReturn;
    }
    delete cReturn;
    return nullptr;
}

/* createHistory creates the history object
 */
Command* CommandType::createHistory(ifstream& stream) {
    History* cHistory = new History();
    cHistory->setCommandType(CommandCase::HistoryCase);
    if (cHistory->setData(stream)) {
        return cHistory;
    }
    delete cHistory;
    return nullptr;
}

/* createInventory creates the inventory object
 */
Command* CommandType::createInventory() {
    Inventory* cInventory = new Inventory();
    return cInventory;
}

/* error displays the error type
 */
void CommandType::error(const char& cType, ifstream& stream) {
    string fullCommand;
    getline(stream, fullCommand, '\n');
    cerr << "Command, invalid command type '" << cType << "':"
        << '\n' << "  " << cType << fullCommand << endl;
}