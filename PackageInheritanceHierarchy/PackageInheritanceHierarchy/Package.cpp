#include<iostream>
#include "Package.h"
#include<stdexcept>
using namespace std;
//Package Constructor
Package::Package(string sN, string sA, string sC, string sS, string sZ,
	string rN, string rA, string rC, string rS, string rZ,
	double weight, double costPerOunce) :senderName(sN), senderAddress(sA), senderCity(sC),
	senderState(sS), senderZipCode(sZ), receiverName(rN), receiverAddress(rA), receiverCity(rC),
	receiverState(rS), receiverZipCode(rZ) {
	setWeight(weight);
	setCostPerOunce(costPerOunce);
}
//Weight setter
void Package::setWeight(double weight) {
	if (weight < 0)
		throw invalid_argument("Weight should be positive value!");
	this->weight = weight;
}
//Cost per ounce Setter
void Package::setCostPerOunce(double costPerOunce) {
	if (costPerOunce < 0)
		throw invalid_argument("Cost Per Ounce should be a positive value!");
	this->costPerOunce = costPerOunce;
}
//Displays all details of the sender
void Package::displaySenderDetails() const{
	cout << "Sender Details\n";
	cout << "Name : " << senderName << endl;
	cout << "Address : " << senderAddress << endl;
	cout << "City : " << senderCity << endl;
	cout << "State : " << senderState << endl;
	cout << "Zip Code : " << senderZipCode << endl << endl;
}
//Displays all details of the receiver
void Package::displayReceiverDetails() const {
	cout << "Receiver Details\n";
	cout << "Name : " << receiverName << endl;
	cout << "Address : " << receiverAddress << endl;
	cout << "City : " << receiverCity << endl;
	cout << "State : " << receiverState << endl;
	cout << "Zip Code : " << receiverZipCode << endl << endl;
}
//Displays additional details like cost and weight
void Package::displayDetails() const {
	cout << "Weight: " << weight << " Ounce" << endl;
	cout << "Standard delivery cost per ounce : $" << costPerOunce << endl;
}
//Calculates total cost of delivering package
double Package::calculateCost() const {
	return weight * costPerOunce;
}

