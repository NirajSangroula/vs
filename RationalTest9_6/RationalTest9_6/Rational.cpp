#include<stdexcept>
#include<sstream>
#include "Rational.h"
using namespace std;
Rational::Rational(int a, int b) { //Constructor with default argument
	setRational(a, b);
}
//SetRational function, that sets reduced values to numerator and denominator
void Rational::setRational(int a, int b) {
	//call utitity function
	int HCF = getHCF(a, b);
	//Set reduced numbers because( We can divide numerator and denominator by any common number)
	setNumerator(a/HCF);
	setDenominator(b/HCF);
}
//Sets numerator
void Rational::setNumerator(int a) {
	numerator = a;
}
//Sets denominator
void Rational::setDenominator(int b) {
	if (b == 0)
		throw invalid_argument("Denominator cannot be 0.");
	else
		denominator = b;
}
//Return numerator and denominator in fractions
string Rational::toRationalString() const{
	ostringstream out;
	out << getNumerator() << "/" << getDenominator();
	return out.str();
}
//Return Rational in decimal
double Rational::toDouble() const {
	return static_cast<double>(numerator) / denominator;
}
//Returns numerator
int Rational::getNumerator() const {
	return numerator;
}
//Returns Denominator
int Rational::getDenominator() const {
	return denominator;
}
//Add to another Rational
void Rational::add(Rational r1) {
	//Perform criss cross multiplication operation   a/b + c/d =( ad + bc ) / bd
	int a = getNumerator() * r1.getDenominator() + r1.getNumerator() * getDenominator();
	int b = getDenominator() * r1.getDenominator();
	//set the rational value (It will automatically be reduced inside the function
	setRational(a, b);
}
//Subtract to another Rational
void Rational::subtract(Rational r1) {
	//Perform criss cross multiplication operation   a/b - c/d =( ad - bc ) / bd
	int a = getNumerator() * r1.getDenominator() - r1.getNumerator() * getDenominator();
	int b = getDenominator() * r1.getDenominator();
	//set the rational value (It will automatically be reduced inside the function
	setRational(a, b);
}
//Multiply to another Rational
void Rational::multiply(Rational r1) {
	setRational(getNumerator() * r1.getNumerator(), getDenominator() * r1.getDenominator());
}
//Divide with another Rational
void Rational::divide(Rational r1) {
	// a / b / c / d = a / b * d / c (Meaning multiplication with numerator and denominator exchanged
	Rational r2{ r1.getDenominator(), r1.getNumerator() };
	multiply(r2);
}
//UTILITY function, returns HCF of given two numbers
int Rational::getHCF(int a, int b) {
	for (int i{(a > b) ? (a) : (b) }; i >= 1 ; i--) { // Loop from 2 to maxnumber/2 To find each factors
		if (a % i == 0 && b % i == 0)
			return i;
	}
}
