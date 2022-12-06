/* @file storemanager.cpp
 * @brief The following code gives the implementations of the storemanager class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "storemanager.h"
#include <iostream>

//storemanager constructor
StoreManager::StoreManager(){}

//destructor
StoreManager::~StoreManager(){}

/* buildCustomers reads the data from the text files and builds a list of customers 
 */
void StoreManager::buildCustomers(ifstream& stream) {
    if (!stream) {
        cout << "Cannot read customer file!" << endl;
        return;
    }

    Customer* ptr;                                 
    while (!stream.eof()) {
        ptr = new Customer();                       

        if (ptr->setData(stream)) {
            if (!customerDatabase.insertCustomer(ptr)) {
                delete ptr;
            }
        } else {
            delete ptr;
        }
    }
    stream.close();
}

/* buildMovies reads the data from the text files and builds a list of movies 
 */
void StoreManager::buildMovies(ifstream& stream) {
    if (!stream) {
        cout << "Cannot read Movies file" << endl;
        return;
    }

    InventoryDatabase* obj;
    InventoryDatabase* dup;

    while (!stream.eof()) {
        obj = Media::buildDVDMovie(stream);
        if (obj != nullptr) {
            if (!database.insert(obj)) {
                if (database.retrieve(*obj, dup)) {
                    dup->addStock(obj->getStock());
                    delete obj;
                }
            }
        }
        obj = dup = nullptr;
    }
    stream.close();
}

/* processCommands processes the commands from the text files
 */
void StoreManager::processCommands(ifstream& stream) {
    if (!stream) {
        cout << "Cannot read command file" << endl;
        return;
    }

    Command* command;
    while (!stream.eof()) {
        command = CommandType::createCommand(stream);
        if (command != nullptr) {
            command->process(database, customerDatabase);
            command = nullptr;
        }
    }
    stream.close();
}