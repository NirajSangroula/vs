#include "OverNightPackage.h"
#include<stdexcept>
#include<string>
#include<iostream>
using namespace std;
//Constructor implementation
OverNightPackage::OverNightPackage(string sN, string sA, string sC, string sS, string sZ,
	string rN, string rA, string rC, string rS, string rZ,
	double weight, double costPerOunce, double aC) :
	Package(sN, sA, sC, sS, sZ, rN, rA, rC, rS, rZ, weight, costPerOunce) {
	setAdditionalFeesPerOunce(aC);
}
//Validation and setting Additional Fees
void OverNightPackage::setAdditionalFeesPerOunce(double aC) {
	if (aC < 0)
		throw invalid_argument("Additional Fees Per Ounce should be positive!");
	this->additionalFeesPerOunce = aC;
}

//Total cost here is (standardCostPerOunce + additionalFeesPerOunce) * weight
double OverNightPackage::calculateCost() const {
	return Package::weight * (Package::costPerOunce + additionalFeesPerOunce);
}
//Displays Other remaining details of cost, weight etc.
void OverNightPackage::displayDetails() const {
	Package::displayDetails();
	cout << "Additional Fees per ounce : $" << additionalFeesPerOunce << endl;
}