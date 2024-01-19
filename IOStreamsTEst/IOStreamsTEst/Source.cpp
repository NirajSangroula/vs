#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdexcept>
#include<string>
using namespace std;
int main() {
	//Program that will update/delete/insert in a table (Name, phoneNo) with menu
	
	//Display menu first:
	int menu{ 1 };
	cout << "Enter menu: 1 -> insert, 2-> display, 3->delete, 4->update" << endl;
	cin >> menu;
	ofstream ifo{ "table.txt", ios::out };
	do {
		if (menu == 1) {
			//Insert code
			cout << "Enter name and phone number: " << endl;
			string name;
			string phone;
			cin >> name >> phone;
			ifo << name << ' ' << phone << endl;
		}
		if (menu == 2) {
			cout << "Name\tPhone no\n";
			ifstream ifObj{ "table.txt", ios::in };
			while (!ifObj.eof()) {
				string name;
				string ph;
				ifObj >> name >> ph;
				cout << name << "\t" << ph << endl;
			}
		}

		cout << "Enter menu: 1 -> insert, 2-> display, 3->delete, 4->update" << endl;
		cin >> menu;
	} while (menu != 0);
	ifo.close();
}
