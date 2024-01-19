#include "CheckingAccount.h"
//Constructor implementation
CheckingAccount::CheckingAccount(double balance, double fee)
	:Account(balance), transactionFee(fee)
{
}
//Redefine credit function to charge transaction fee
void CheckingAccount::credit(double amount)
{
	Account::credit(amount);
	balance -= transactionFee;
}
//Redefine debit function to charge transaction fee if successful
bool CheckingAccount::debit(double amount)
{
	if (Account::debit(amount)) {
		balance -= transactionFee;
		return true;
	}
	return false;
}
