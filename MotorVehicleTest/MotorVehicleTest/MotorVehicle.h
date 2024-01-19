#include<string>
using namespace std;
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
//MotorVehicle class
class MotorVehicle
{
public:
	//Parameterised constructor(color, make, yearOfManuFacture)
	MotorVehicle(string, string, int);

	//Getter and Setter function definitions for each data members
	string getMake() const;
	void setMake(string);
	string getFuelType() const;
	void setFuelType(string);
	int getYearOfManufacture() const;
	void setYearOfManufacture(int);
	string getColor() const;
	void setColor(string);
	int getEngineCapacity() const;
	void setEngineCapacity(int);

	//Function to print all car attributes
	void displayCarDetails() const;

	//Operator overloadings
	bool operator==(MotorVehicle);
	bool operator!=(MotorVehicle);
	bool operator>(MotorVehicle);
	friend ostream& operator<<(ostream&, MotorVehicle);

private:
	//Data members of MotorVehicle
	string make;
	string fuelType;
	int yearOfManufacture;
	string color;
	int engineCapacity;

};

#endif // !MOTORVEHICLE_H


