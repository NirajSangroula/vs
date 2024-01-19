#include<iostream>
#include<stdexcept>
#include "Weight.h"
using namespace std;
int main() {
	try {
		Weight w1;
		cout << "Enter w1 ";
		cin >> w1;
		cout << " W1 : " << w1;
		Weight w2{ 4, 15};
		w2.setOunces(4).setPounds(3);
		cout << "W2 : " << w2;
		Weight w3 = w1 + w2;
		cout << "W3 : W1 + W2 \n" << w3 << endl;
		return 0;
	}
	catch (invalid_argument e) {
		cerr << e.what();
	}
}