//Class implementation for Name
#include "Name.h"
#include<string>
#include<sstream>
using namespace std;
//Constructor implementation
Name::Name(string firstName, string middleName, string lastName, string salutation){
	setFirstName(firstName);
	setMiddleName(middleName);
	setLastName(lastName);
	setSalutation(salutation);
}
//To string method
string Name::toString() const{
	//Create ostringstream object from sstream header library
	ostringstream out;
	//Create a string with proper formatting
	out << getSalutation() << " " << getLastName() << ", " << getFirstName() << " "
		<< getMiddleName();
	//return the formatted string
	return out.str();

}
//Setter methods for each data members
void Name::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Name::setLastName(string lastName) {
	this->lastName = lastName;
}
void Name::setMiddleName(string middleName) {
	this->middleName = middleName;
}
void Name::setSalutation(string salutation) {
	this->salutation = salutation;
}
//getter methods for each data members
string Name::getFirstName() const{
	return firstName;
}
string Name::getLastName() const {
	return lastName;
}
string Name::getMiddleName() const {
	return middleName;
}
string Name::getSalutation() const {
	return salutation;
}