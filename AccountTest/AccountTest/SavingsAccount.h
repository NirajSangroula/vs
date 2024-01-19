#include "Account.h"
#ifndef SACCOUNT_H
#define SACCOUNT_H

class SavingsAccount
	: public Account
{
public:
	//Constructor
	SavingsAccount(double, double);
	double calculateInterest() const;
private:
	//interestRate in Percents
	double interestRate;
};
#endif

