#include "Customer.h"
#include "Transaction.h"

Customer::Customer() {
    ID = 0;
    FirstName = "";
    LastName = "";
}

Customer::~Customer(){
    for (auto temp: History) {
        delete temp;
    }
}

int Customer::GetID() {
    return ID;
}

void Customer::AddTransactionHistory(Transaction* Trans){
    History.push_back(Trans);
}

void Customer::DisplayHistory(){
    cout << "Customer: " << ID << " History" << endl;
    for (auto temp: History) {
        temp->Display();
    }
}

bool Customer::SetData(ifstream& FileName) {
    FileName >> ID >> LastName >> FirstName;
    return (ID >= MINID && ID <= MAXID);
}

bool Customer::isBorrowed(Movie* Mov) {
    int Borrowed = 0;
    int NotBorrowed = 0;
    for (auto temp : History) {
        if (temp->GetCommand() == 'B' &&
            temp->GetTitleMovie()->TransactionDisplay() == 
            Mov->TransactionDisplay()) {
            Borrowed++;
        }
        else if (temp->GetCommand() == 'R' &&
                 temp->GetTitleMovie()->TransactionDisplay() == 
                 Mov->TransactionDisplay()) {
            NotBorrowed++;
        }
    }
    return NotBorrowed < Borrowed;
}
