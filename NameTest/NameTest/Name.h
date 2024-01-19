//Name class Header File
#include<string>
#ifndef NAME_H
#define NAME_H

using std::string;
class Name
{
private:
	//Data members for name
	string firstName, middleName, lastName, salutation;
public:
	//Parameterized constructor to initialize names and salutation
	Name(string, string, string, string);

	//String representation with proper formatting
	string toString() const;

	//getter methods for each data members
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	string getSalutation() const;
	//setter methods for each data members
	void setFirstName(string);
	void setMiddleName(string);
	void setLastName(string);
	void setSalutation(string);
};
#endif
