#include<string>
#ifndef PRODUCT_H
#define PRODUCT_H
class Product
{
public:
	//Constructor with arguement Price
	Product(double);
	//Destructor
	~Product();
	//Static member function to return count
	static int getCount();
	//Setter and Getter functions
	void setPrice(double);
	double getPrice() const;
	//toString method to return string representation of the object
	std::string toString() const;
private:
	//Data members
	double price;
	//Static data member shared by all objects
	static int count;
};
#endif