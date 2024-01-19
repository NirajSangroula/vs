#include "VicobaAccount.h"
//Constructor implementation
VicobaAccount::VicobaAccount(double amount, double duration) {
	setAmount(amount);
	setDuration(duration);
}
//Default setting of the static member annual interest rate (10%)
double VicobaAccount::annualInterestRate{ 10 };
//Setter methods for all data members
void VicobaAccount::setAmount(double amount) {
	this->amount = amount;
}
void VicobaAccount::setDuration(double duration) {
	this->duration = duration;
}
void VicobaAccount::setAnnualInterestRate(double rate) {
	VicobaAccount::annualInterestRate = rate;
}

//Getter method implementation for all members
double VicobaAccount::getAmount() const{
	return amount;
}
double VicobaAccount::getDuration() const {
	return duration;
}
double VicobaAccount::getAnnualInterestRate() {
	return VicobaAccount::annualInterestRate;
}
double VicobaAccount::getPaymentAmount() const {
	//Total payment amount = paymentAmount + Interest, in this case, Simple Interest = p * t * r / 100
	return getAmount() + (getAmount() * getDuration() * getAnnualInterestRate() / 100);
}
