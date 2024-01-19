// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//trim function to eliminate repeating digits
#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	//Create ifstream object to open the file
	ifstream io{ "fractions.dat", ios::in | ios::binary };
	if (!io) {
		//Print error if exists
		cerr << "File can't be opened" << endl;
		exit(EXIT_FAILURE);
	}
	//Create a string to store each line
	string line;
	//Read entire line at once from file
	while (getline(io, line)) {
		//Use istringstream to process each line
		istringstream iss(line);
		int a, b;
		iss >> a;
		//If it doesnot have denominator or the second value, set it to 1
		if (!(iss >> b)) {
			b = 1;
		}
		//Finally display the values
		cout << a << "\t" << b << "\t" << static_cast<double>(a) / b << endl;
	}
}