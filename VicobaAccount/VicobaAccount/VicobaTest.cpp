#include<iostream>
#include "VicobaAccount.h"
using namespace std;
int main() {
	//Creating an account with Initial Amount 1000 and 10 years of duration
	VicobaAccount nirajAccount{ 1000, 10 };
	//Set annual interest rate to 2%
	VicobaAccount::setAnnualInterestRate(2);

	//Display all data member values and Total payment amount with proper formatting
	cout << "For Niraj Account \nAmount : $" << nirajAccount.getAmount() << endl;
	cout << "Duration : " << nirajAccount.getDuration() << " years\n";
	cout << "Annual interest rate: " << VicobaAccount::getAnnualInterestRate() << "%" << endl;
	cout << "Total payment amount : $" << nirajAccount.getPaymentAmount() << endl;
	return 0;
}