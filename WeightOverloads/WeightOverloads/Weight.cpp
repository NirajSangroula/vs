#include "Weight.h"
#include<stdexcept>
#include<iomanip>
//Constructor implementation
Weight::Weight(){
	setPounds(0);
	setOunces(0);
}

Weight::Weight(double p, double o)
{
	setPounds(p);
	setOunces(o);
}
//Setter and getter methods implementations
Weight Weight::setPounds(double p)
{
	if (p < 0)
		throw std::invalid_argument("Weight cannot be negative");
	pounds = p;
	return *this;
}

Weight Weight::setOunces(double o)
{
	if (o < 0 || o >= 16)
		throw std::invalid_argument("Ounce cannot be negative or >= 16");
	ounces = o;
	return *this;
}

double Weight::getPounds() const
{
	return pounds;
}

double Weight::getOunces() const
{
	return ounces;
}

//Operator overload +
Weight Weight::operator+(Weight& w)
{

	double ounce{static_cast<double>(static_cast<int>(getOunces() + w.getOunces()) % 16)};
	double p{ getPounds() + w.getPounds() + static_cast<int>(getOunces() + w.getOunces()) / 16 };
	return Weight{p, ounce};
}

// << operator overload
std::ostream& operator<<(std::ostream& o, const Weight& w)
{
	o << w.getPounds() << "lb" << w.getOunces() << "oz" << std::endl;
	return o;
}
// >> operator overload
std::istream& operator>>(std::istream& i, Weight& w)
{
	double pounds{ 0 }, ounces{ 0 };
	i >> pounds;
	i >> std::setw (2);
	i.ignore(2); // ignore lb
	i >> ounces;
	i.ignore(2); // ignore oz
	w.setOunces(ounces);
	w.setPounds(pounds);
	return i;
}
