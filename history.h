/* @file history.h
 * @brief The following code gives the declarations of the history class.
 *  This class shows the histroy of a transaction and is the child class of command.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "command.h"

class History : public Command {
    friend ostream& operator<<(ostream&, const History&);

public:
    History();

    ~History();

    bool setData(ifstream& stream);

    bool processHistory(CustomerDatabase&);

private:

    virtual ostream& out(ostream&) const override;
};
#endif