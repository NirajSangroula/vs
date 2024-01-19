#include "SavingsAccount.h"
//Constructor implementation for Savings account
SavingsAccount::SavingsAccount(double balance, double r) 
	: Account(balance), interestRate(r)
{
}
//Calculate interest: interest = rate * balance ( rate = percents / 100)
double SavingsAccount::calculateInterest() const
{
	return interestRate / 100 * balance;
}
