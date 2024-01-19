#ifndef CHECKACCOUNT_H
#define CHECKACCOUNT_H
#include "Account.h"

class CheckingAccount :
    public Account
{
public:
    //Constructor
    CheckingAccount(double, double);
    //Redefine credit and debit functions
    void credit(double);
    bool debit(double);
private:
    //Data member to store fees charged for every transaction
    double transactionFee;
};
#endif

