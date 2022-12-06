/* @file borroworreturn.h
 * @brief The following code gives the declarations of the borroworreturn class.
 *  When a customer borrows a movie from the store this class deals with that command. 
 *  The class is also the parent class Borrow
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _BORROWORRETURN_H_
#define _BORROWORRETURN_H_
#include "command.h"

class BorrowOrReturn : public Command
{
    friend ostream& operator<<(ostream&, const BorrowOrReturn&);

public:
    BorrowOrReturn();

    ~BorrowOrReturn();

    bool setData(ifstream&);

protected:
    MediaType mediaType;

    MovieType movieType;

    InventoryDatabase* media;

    void processComedy(ifstream&, InventoryDatabase*&);

    void processClassic(ifstream&, InventoryDatabase*&);

    void processDrama(ifstream&, InventoryDatabase*&);

    void processError(ifstream&, const string&, const string&);

    virtual ostream& out(ostream&) const;
};
#include "borrow.h"
#include "return.h"
#endif