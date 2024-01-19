#include "MotorVehicle.h"
#include<iostream>
MotorVehicle::MotorVehicle(string color, string make, int yearOfManufacture) {
	setColor(color);
	setMake(make);
	setYearOfManufacture(yearOfManufacture);
}

//Setter function implementations:
//Sets color
void MotorVehicle::setColor(string color) {
	this->color = color;
}
//Sets make
void MotorVehicle::setMake(string make) {
	this->make = make;
}
//Sets fuel type
void MotorVehicle::setFuelType(string fuelType) {
	this->fuelType = fuelType;
}
//Sets the year of vechicle manufacture
void MotorVehicle::setYearOfManufacture(int yom) {
	this->yearOfManufacture = yom;
}
//sets the engine capacity
void MotorVehicle::setEngineCapacity(int ec) {
	this->engineCapacity = ec;
}

//Getter function implementations
//Returns color
string MotorVehicle::getColor() const {
	return color;
}
//returns make
string MotorVehicle::getMake() const {
	return make;
}
//Returns type of fuel
string MotorVehicle::getFuelType() const {
	return fuelType;
}
//Returns year of vehicle manufacture
int MotorVehicle::getYearOfManufacture() const {
	return yearOfManufacture;
}
//Returns capacity of engine
int MotorVehicle::getEngineCapacity() const {
	return engineCapacity;
}
//Displays car details in proper formatting details
void MotorVehicle::displayCarDetails() const{
	cout << "Make : " << getMake() << endl;
	cout << "Color : " << getColor() << endl;
	cout << "Fuel type : " << getFuelType() << endl;
	cout << "Year of Manufacture : " << getYearOfManufacture() << endl;
	cout << "Engine Capacity : " << getEngineCapacity() << endl;
}
//Overload == operator for the class
bool MotorVehicle::operator==(MotorVehicle v1) {
	//Returns true if each of properties between the vehicles match
	return ((v1.getColor() == getColor()) 
		&&( v1.getEngineCapacity() == getEngineCapacity()) 
		&& (v1.getFuelType() == getFuelType()) 
		&& (v1.getMake() == getMake()) 
		&& (v1.getYearOfManufacture() == getYearOfManufacture()));
}

//Overload != operator
bool MotorVehicle::operator!=(MotorVehicle v1) {
	//Returns true if each of properties between the vehicles match
	return ((v1.getColor() != getColor())
		|| (v1.getEngineCapacity() != getEngineCapacity())
		|| (v1.getFuelType() != getFuelType())
		|| (v1.getMake() != getMake())
		|| (v1.getYearOfManufacture() != getYearOfManufacture()));
}

//Overload > operator for the class
bool MotorVehicle::operator>(MotorVehicle v1) {
	return getYearOfManufacture() > v1.getYearOfManufacture(); //1900 < 1901 But 1900 is greater than 1901 (Older so... There's twist plot)
}

//Output operator overloading
ostream& operator<<(ostream& o, MotorVehicle m) {
	o << "Make : " << m.getMake() << endl;
	o << "Color : " << m.getColor() << endl;
	o << "Fuel type : " << m.getFuelType() << endl;
	o << "Year of Manufacture : " << m.getYearOfManufacture() << endl;
	o << "Engine Capacity : " << m.getEngineCapacity() << endl;
	return o;
}