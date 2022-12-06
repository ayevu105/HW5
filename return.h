/* @file return.h
 * @brief The following code gives the declarations of the return class.
 *  This class is the child class of BorrowOrReturn
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _RETURN_H_
#define _RETURN_H_
#include "borroworreturn.h"

class Return : public BorrowOrReturn {
    friend ostream& operator<<(ostream&, const Return&);

public:
    Return();

    ~Return();

    bool processReturn(Database&, CustomerDatabase&);

private:

    virtual ostream& out(ostream&) const override;
};
#endif