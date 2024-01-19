#include<iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;
int main() {
	//Create Account with initial balance 10
	Account a{ 10 };
	cout << "For Account\n";
	cout << "Balance : $" << a.getBalance() << endl;
	//Credit 43 to account
	cout << "Credit $43\n";
	a.credit(43);
	cout << "Balance : $" << a.getBalance() << endl;
	cout << "Try debit $44" << endl;
	//Debit 44 if possible
	if (a.debit(44)) {
		cout << "Succeed $44 debit\n";
	}
	cout << "Balance : $" << a.getBalance() << endl;
	//Debit 10 if possible
	cout << "Try debit $10 \n";
	if (a.debit(10)) {
		cout << "$10 withdrawn \n";
		cout << "Balance : $" << a.getBalance() << endl;
	}


	cout << "\nFor Checking Account\n";
	//Create Checking Account Object
	CheckingAccount ca{ 1000, 10 };
	cout << "Balance : $" << ca.getBalance() << endl;
	//Perform some transactions and print balance
	cout << "Credit $100" << endl;
	ca.credit(100);
	cout << "Balance : $" << ca.getBalance() << endl;
	cout << "Debit 1080" << endl; 
	if (ca.debit(1080)) {
		cout << "$1080 withdrawn \n";
	}
	cout << "Balance : $" << ca.getBalance() << endl;

	cout << "\nFor Saving Account\n";
	//Create saving account object
	SavingsAccount sa{ 1000, 5 };
	//Perform some transactions and print balance
	cout << "Balance : $" << sa.getBalance() << endl;
	cout << "Adding interest of " << sa.calculateInterest() << endl;
	//Add interest to balance
	sa.credit(sa.calculateInterest());
	cout << "Balance : $" << sa.getBalance() << endl;
	cout << "Debit $100 \n";
	if (sa.debit(100)) {
		cout << "$100 withdrawn \n";
	}
	cout << "Balance : $" << sa.getBalance() << endl;

	return 0;
}