/* @file borrow.h
 * @brief The following code gives the declarations of the borrow class.
 *  When a customer borrows a movie from the store this class deals with that command. 
 *  The class is also the child class BorrowOrReturn
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _BORROW_H_
#define _BORROW_H_
#include "borroworreturn.h"

class Borrow : public BorrowOrReturn {

    friend ostream& operator<<(ostream&, const Borrow&);

public:

    Borrow();

    ~Borrow();

    bool processBorrow(Database&, CustomerDatabase&);

private:

    virtual ostream& out(ostream&) const override;

};
#endif