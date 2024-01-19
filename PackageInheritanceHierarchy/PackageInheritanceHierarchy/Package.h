#include<string>
#ifndef PACKAGE_H
#define PACKAGE_H
class Package
{
public:
	//Package class Constructor ((Sender Details), (Receiver Details), Weight, Cost Per Ounce)
	Package(std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, std::string,
		double, double);

	//Calculate total cost = weight * costPerOunce
	double calculateCost() const;
	//Validator and setter methods for weight and constPerOunce
	void setWeight(double);
	void setCostPerOunce(double);
	//Display all details of Sender
	void displaySenderDetails() const;
	//Display all details of receiver
	void displayReceiverDetails() const;
	//Display detailsOfPackageDelivery
	void displayDetails() const;
protected:
	//Sender details data members
	std::string senderName;
	std::string senderAddress;
	std::string senderCity;
	std::string senderState;
	std::string senderZipCode;
	//Receiver details data members
	std::string receiverName;
	std::string receiverAddress;
	std::string receiverCity;
	std::string receiverState;
	std::string receiverZipCode;

	//Weight in Ounces MUST BE POSITIVE
	double weight;
	//Cost Per Ounce in Dollars($) MUST BE POSITIVE
	double costPerOunce;
};
#endif

