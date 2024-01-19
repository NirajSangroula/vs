#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
public:
	//Constructor
	Account(double);
	//Add balance to account
	void credit(double);
	//Withdraw money if possible
	bool debit(double);
	//Display current balance
	double getBalance();
protected:
	//Data member balance
	double balance;
};
#endif

