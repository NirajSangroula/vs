#include<iostream>
#include "OverNightPackage.h"
#include "Package.h"
#include "TwoDayPackage.h"
using namespace std;
int main() {
	try {
		cout << "Package Object: \n";
		Package p{ "Niraj Sangroula", "66 Prouse Dr", "Brampton", "ON", "L6V3A3",
	"Ranju Sangroula", "12 Harkalal Margha", "Birtamode", "1", "402345", 2, 3, };
		//Display details of Sender and Receiver
		p.displaySenderDetails();
		p.displayReceiverDetails();
		p.displayDetails();
		//Display total cost of shipping
		cout << "Total cost : $" << p.calculateCost() << endl << endl;

		//TwoDayPackage Object creation and calculateCost
		cout << "TwoDayPackage Object: \n";
		TwoDayPackage p1{ "Nitesh Karki", "64 Bolvaird Dr", "Brampton", "ON", "L6Y3C3",
	"Dikshya Sangroula", "13 Harkalal Margha", "Birtamode", "1", "402345", 3, 4, 5};
		//Display details of Sender and Receiver
		p1.displaySenderDetails();
		p1.displayReceiverDetails();
		p1.displayDetails();
		//Display total cost of shipping
		cout << "Total cost : $" << p1.calculateCost() << endl << endl;

		//OverNight Package Object Creation and calculateCost

		cout << "OverNightPackage Object: \n";
		OverNightPackage p2{ "Dikshya Lama", "2 Goreway Dr", "Brampton", "ON", "L6Z3B3",
	"Sita Vetwal", "10 Harkalal Margha", "Birtamode", "1", "402345", 3, 10, 2 };
		//Display details of Sender and Receiver
		p2.displaySenderDetails();
		p2.displayReceiverDetails();
		p2.displayDetails();
		//Display total cost of shipping
		cout << "Total cost : $" << p2.calculateCost() << endl << endl;
	}
	catch (invalid_argument e) {
		cerr << e.what();
	}
	return 0;
}