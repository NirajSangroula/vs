#include<string>

#ifndef RATIONAL_H
#define RATIONAL_H
class Rational
{
private:
	//Numerator and denominator containers
	int numerator;
	int denominator;
	//Private utility functions
	static int getHCF(int, int);
public:
	//Default argument constructor
	explicit Rational(int = 1, int = 1);
	//Setters and getters
	void setRational(int, int);
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator() const;
	int getDenominator() const;
	//Operations
	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
	//Representations of the number
	std::string toRationalString() const;
	double toDouble() const;
};
#endif