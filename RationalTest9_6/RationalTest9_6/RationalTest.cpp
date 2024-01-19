#include<iostream>
#include<stdexcept>
#include "Rational.h"
using namespace std;
int main() {
	try {
		//Create two Rational Number objects
		Rational r1{ 12, 4 }, r2{ 2, 2 };
		//Display reduced rational string values first
		cout << "Value of r1: " << r1.toRationalString() << endl;
		cout << "Value of r2: " << r2.toRationalString() << endl;

		cout << "Double value of r2 " << r2.toDouble() << endl;

		r1.add(r2);
		//After addition, display value
		cout << " r1 + r2 = " << r1.toRationalString() << endl;

		r1.setRational(16, 6); //Reset r1 values
		r1.subtract(r2);
		//Subtracted value display
		cout << " r1 - r2 = " << r1.toRationalString() << endl;

		r1.setRational(16, 6); //Reset r1 values
		r1.multiply(r2);
		//Product display
		cout << " r1 * r2 = " << r1.toRationalString() << endl;

		r1.setRational(16, 6); //Reset r1 values
		r1.divide(r2);
		//Division display
		cout << " r1 / r2 = " << r1.toRationalString() << endl;
	}
	catch (invalid_argument& e) {
		//Error message displayed if any exception is thrown
		cerr << "Exception: " << e.what() << endl;
	}
	
	return 0;
}