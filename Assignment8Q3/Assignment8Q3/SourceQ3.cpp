#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include "Tools.h"
using namespace std;
int main() {

	//Create outStreamObject
	fstream outTools{ "tools.dat", ios::out | ios::binary };
	if (!outTools) {
		cerr << "File can't be opened." << endl;
		exit(EXIT_FAILURE);
	}
	//Create 100 empty records
	for (int i{ 0 }; i < 100; i++) {
		Tools t;
		outTools.seekp(i * sizeof(Tools));
		outTools.write(reinterpret_cast<const char*>(&t), sizeof(Tools));
	}
	//Show menu and ask user to choose an option until they enter invalid option
	int n{ 0 };
	cout << "Enter 1 to insert record \n2 to list all tools\n3 to delete a record\n4 to update the record\n";

	cin >> n;
	while (n > 0 && n < 5) {
		if (n == 1) {
			outTools.open("tools.dat", ios::out | ios::binary);
			//Ask for record number and enter contents in it
			cout << "Enter record number, Tool name, Quantity and Cost: ";
			int rn{ 0 }, qty{ 0 };
			double cost{ 0 };
			string name{ "" };
			cin >> rn >> name >> qty >> cost;
			//Create an object
			Tools t{ rn, name, qty, cost };
			//find where to insert contents
			outTools.seekp((t.getRecord() - 1) * sizeof(Tools));
			//Write to the position
			outTools.write(reinterpret_cast<const char*>(&t), sizeof(Tools));
			outTools.close();
		}
		if (n == 2) {
			fstream inTools{ "tools.dat", ios::in | ios::binary };
			if (!inTools) {
				cerr << "File can't be opened." << endl;
				exit(EXIT_FAILURE);
			}

			cout << left << setw(10) << "Record" << setw(15) << "Name" << setw(10) << "Quantity" << setw(15) << "Cost" << endl;
			Tools t;
			inTools.read(reinterpret_cast<char*>(&t), sizeof(Tools));
			while (inTools) {
				inTools.read(reinterpret_cast<char*>(&t), sizeof(Tools));
				//Display if it is not empty
				if (t.getRecord() != 0)
					t.display();
			}
			inTools.close();
		}
		if (n == 4) {
			//Ask for record number and enter contents in it
			cout << "Which record number to update: ";
			int rn{ 0 }, qty{ 0 };
			double cost{ 0 };
			string name{ "" };
			cin >> rn;
			cout << "Enter new name, qty, cost";
			cin >> name >> qty >> cost;
			Tools t{ rn, name, qty, cost };
			outTools.seekp((t.getRecord() - 1) * sizeof(Tools));
			outTools.write(reinterpret_cast<const char*>(&t), sizeof(Tools));
			outTools.close();
		}
		if (n == 3) {
			//Ask for record number and enter contents in it
			cout << "Which record number to delete: ";
			int rn;
			cin >> rn;
			Tools t;
			outTools.seekp((rn - 1) * sizeof(Tools));
			outTools.write(reinterpret_cast<const char*>(&t), sizeof(Tools));
			outTools.close();
		}
		cout << "Enter 1 to insert record \n2 to list all tools\n3 to delete a record\n4 to update the record\n";
		cin >> n;
	}
	
	return 0;
}

