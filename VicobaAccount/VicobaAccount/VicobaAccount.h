//VicobaAccount Class Header
#ifndef VICOBAACCOUNT_H
#define VICOBAACCOUNT_H
class VicobaAccount
{
private:
	//Data members for loan
	static double annualInterestRate;
	double amount, duration;
public:
	//Constructor
	VicobaAccount(double, double);
	//Setter methods
	void setAmount(double);
	void setDuration(double);
	static void setAnnualInterestRate(double);
	//Getter Methods
	static double getAnnualInterestRate();
	double getAmount() const;
	double getDuration() const;
	//Returns Total Payment Amount calculated using simple interest
	double getPaymentAmount() const;
};
#endif