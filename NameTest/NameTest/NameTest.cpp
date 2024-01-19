#include<iostream>
#include "Name.h";
using namespace std;
int main() {
	//Create an object with all properties initialized in constructor
	Name n1{ "Ram", "Kumar", "Thapa", "Mr." };
	//Invoke toString method
	cout << n1.toString() << endl;

	//Modify middle name and salutation
	n1.setMiddleName("Kumari");
	n1.setSalutation("Mrs");
	//Display each values using getter Methods
	cout << "After modification, Salutation is " << n1.getSalutation() << endl;
	cout << "First, middle and last name in order: " << n1.getFirstName() << " " << n1.getMiddleName() << " " << n1.getLastName() << endl;
	cout << "Proper name with salutation\n";
	//Display toString method
	cout << n1.toString() << endl;
	return 0;
}