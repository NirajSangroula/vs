#include "TwoDayPackage.h"
#include<string>
#include<stdexcept>
#include<iostream>
using namespace std;
//Two Day Package class Constructor
TwoDayPackage::TwoDayPackage(string sN, string sA, string sC, string sS, string sZ,
	string rN, string rA, string rC, string rS, string rZ,
	double weight, double costPerOunce, double flatFee) :
	Package(sN, sA, sC, sS, sZ, rN, rA, rC, rS, rZ, weight, costPerOunce) {
	setFlatFee(flatFee);
}
//Flat fee setter function
void TwoDayPackage::setFlatFee(double flatFee) {
	if (flatFee < 0)
		throw invalid_argument("Fees should be positive!");
	this->flatFee = flatFee;
}
//Calculates total cost : Total cost here is flatFees + CostCalculatedByBaseClass
double TwoDayPackage::calculateCost() const {
	return Package::calculateCost() + flatFee;
}
//Displays other details for delivery cost
void TwoDayPackage::displayDetails() const {
	Package::displayDetails();
	cout << "Flat fee : $" << flatFee << endl;
}