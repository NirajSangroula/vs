#include<iostream>
#include<string>
#ifndef WEIGHT_H
#define WEIGHT
class Weight
{
public:
	//Constructors
	Weight();
	Weight(double, double);
	//Setter and getter functions
	Weight setPounds(double);
	Weight setOunces(double);
	double getPounds() const;
	double getOunces() const;
	//Overload <<, >> and + operators
	friend std::ostream& operator <<(std::ostream& o, const Weight&);
	friend std::istream& operator >> (std::istream& o, Weight&);
	Weight operator + (Weight& w);
private:
	double pounds;
	double ounces;
};
#endif
