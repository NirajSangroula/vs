#include "Quadratic.h"
#include<iostream>
#include<sstream>
#include<iomanip>
//Parameterised constructor with default variable arguement
Quadratic::Quadratic(double a, double b, double c, char v = 'x') {
	//Don't let a to be 0 (Instead assign 1
	this->a = (a == 0) ? 1 : a;
	this->b = b;
	this->c = c;
	this->variable = v;
}
//Default constructor without parameter
Quadratic::Quadratic() :Quadratic(1, 0, 0) {}
//add function to add another quadratic equation
void Quadratic::add(Quadratic q){
	a += q.a;
	b += q.b;
	c += q.c;
}
//subtract function implementation
void Quadratic::subtract(Quadratic q) {
	a -= q.a;
	b -= q.b;
	c -= q.c;
}
//toString function to return string representation of the quadratic equation
string Quadratic::toString() const {
	ostringstream os;
	os << a << variable << "^2 + " << b << variable << " + " << c << " = 0";
	return os.str();
}
//Solve and display solutions of quadratic equation
void Quadratic::solve() const {
	// i = b^2 - 4ac
	double i = b * b - 4 * a * c;
	//Check if there are real roots
	if (i >= 0) {
		//Solutions, using [-b (+/-) b^2 - 4ac] / 2a
		double x1 = (-b + sqrt(i)) / (2 * a);
		double x2 = (-b - sqrt(i)) / (2 * a);

		cout << "Solutions are " << x1 << " and " << x2 << endl;
	}
	else {
		cout << "No real roots";
	}
}

//Overloading operators
//Operator +
Quadratic Quadratic::operator+(Quadratic q) const {
	//Set coefficients which are sum of this object and q
	Quadratic q1{a + q.a, b + q.b, c + q.c };
	return q1;
}

//Operator -
Quadratic Quadratic::operator-(Quadratic q) const {
	//Set coefficients which are difference of this object and q
	Quadratic q1{ a - q.a, b - q.b, c - q.c };
	return q1;
}
//Overload output operator
ostream& operator<<(ostream& o, Quadratic q) {
	o << q.a << q.variable << "^2 + " << q.b << q.variable << " + " << q.c << " = 0";
	return o;
}