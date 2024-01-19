#include "MotorVehicle.h"
#include<iostream>
using namespace std;
int main() {
	//Instantiate a vehicle v1
	MotorVehicle v1{ "Red", "Tesla", 2009 };
	v1.setEngineCapacity(100);
	v1.setFuelType("Electricity");

	//INstantiate another vehicle v2
	MotorVehicle v2{ "Green", "Ferrari", 2019 };
	v2.setEngineCapacity(1000);
	v2.setFuelType("Petrol");

	
	//Instantiate a vehicle v1
	MotorVehicle v3{ "Red", "Tesla", 2009 };
	v3.setEngineCapacity(100);
	v3.setFuelType("Electricity");

	//Print the details of all motors
	cout << "Details of v1 \n\n" << v1 << endl << endl;
	cout << "Details of v2 \n\n" << v2 << endl << endl;
	cout << "Details of v3 \n\n" << v3 << endl << endl;

	//Show compare results

	cout << "Comparing v1 == v3 : " << ((v1 == v3)?"True":"False") << endl;
	cout << "Comparing v1 == v2 : " << ((v1 == v2) ? "True" : "False") << endl;
	cout << "Comparing v1 != v3 : " << ((v1 != v3) ? "True" : "False") << endl;
	cout << "Comparing v1 != v2 : " << ((v1 != v2) ? "True" : "False") << endl;
	cout << "Comparing v2 > v1 : " << ((v2 > v1) ? "True" : "False") << endl;

	cout << "Comparing v1 > v2 : " << ((v1 > v2) ? "True" : "False") << endl;
	return 0;
}