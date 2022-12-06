/* @file database.h
 * @brief The following code gives the declarations of the database class.
 *  This class controls and modifies the media in InventoryDatabase
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <iostream>
#include <map>
#include "bst.h"
#include "inventorydatabase.h"

using namespace std;

class Database{
public:

    Database();

    ~Database();

    bool insert(InventoryDatabase* media);

    bool retrieve(const InventoryDatabase& target, InventoryDatabase*& retriever);

    bool remove(const InventoryDatabase& target);

    void display() const;

    int getTotalMedia() const;

    int getTotalMovie() const;

private:

    map<MovieType, BST<InventoryDatabase>> movies;

    BST<InventoryDatabase> comedies;

    BST<InventoryDatabase> dramas;

    BST<InventoryDatabase> classics;

    bool insertMovie(InventoryDatabase* movie);

    bool retrieveMovie(const InventoryDatabase& target, InventoryDatabase*& retriever);

    bool removeMovie(const InventoryDatabase& target);
};
#endif