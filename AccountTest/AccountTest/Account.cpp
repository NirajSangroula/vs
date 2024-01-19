#include "Account.h"
#include <iostream>
using namespace std;
//Account Constructor with validator
Account::Account(double i)
{
	if (i < 0) {
		cout << "Account balance should be positive!" << endl;
		this->balance = 0;
	}
	else
		balance = i;
}
//Credit function
void Account::credit(double amount)
{
	balance += amount;
}
//Debit function
bool Account::debit(double amount)
{
	if (amount > balance) {
		cout << "Debit amount exceeded account balance!" << endl;
		return false;
	}
	else
		balance -= amount;
	return true;
}
//Get balance function
double Account::getBalance()
{
	return balance;
}
