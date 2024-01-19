#include "Product.h"
#include<iostream>
#include<sstream>
//Initializing static data member count to 0
int Product::count = 0;
//Constructor
Product::Product(double price) :price(price) {
	Product::count++;
}
//Destructor: Decreases count and prints message
Product::~Product()
{
	count--;
	std::cout << "A product has been destroyed\n";
}

//getter and setters for data members

int Product::getCount()
{
	return count;
}



void Product::setPrice(double price)
{
	this->price = price;
}

double Product::getPrice() const
{
	return price;
}
//To string method implementation
std::string Product::toString() const
{
	std::ostringstream out;
	out << "$" << price << std::endl;
	return out.str();
}

