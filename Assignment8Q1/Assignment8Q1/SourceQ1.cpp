#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	//Read lower and upper limit
	cout << "Enter lower and upper limit in decimals:\n";
	int u{ 0 }, l{ 0 };
	cin >> l >> u;
	//Print the table header with necessary spacing
	cout << "Decimal\tOctal\tHexadecimal\n";
	for (int i{ l }; i <= u; i++) {
		//Display the value of i in decimal, octal and hexadecimal using setbase() manipulator setting appropriate spaces using \t
		cout << setbase(10) << i << "\t" << setbase(8) << i << "\t" << setbase(16) << i << "\n";
	}
	return 0;
}