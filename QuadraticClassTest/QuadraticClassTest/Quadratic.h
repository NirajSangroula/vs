#include<string>
using namespace std;
#ifndef QUADRATIC_H
#define QUADRATIC_H
class Quadratic
{
public:
	//Parameterised constructor
	Quadratic(double, double, double, char);
	//Default Constructor
	Quadratic();
	//Member functions
	//add another Quadratic equation to this equation
	void add(Quadratic);
	//subtract anothe rQuadratic equation from this equation
	void subtract(Quadratic);
	//String representation of quadratic equation eg. 3x^2+4x+3
	string toString() const;
	//Display solutions if they exist
	void solve() const;

	//Overloaded operators
	Quadratic operator+(Quadratic) const;
	Quadratic operator-(Quadratic) const;
	friend ostream& operator<<(ostream&, Quadratic);

private:
	//Coefficients each terms
	double a, b, c;
	//Variable
	char variable;


};
#endif // !QUADRATIC_H


