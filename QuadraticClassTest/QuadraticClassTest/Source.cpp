#include "Quadratic.h"
#include<iostream>
using namespace std;
int main() {
	//Create Quadratic objects
	Quadratic q1{};
	Quadratic q2(2, 4, 3, 'v');
	Quadratic q3(2, 5, 2, 'v');
	
	//Display equations and solve
	cout << "Q1 : " << q1 << endl;
	q1.solve();
	cout << "\n\nQ2 : " << q2 << endl;
	q2.solve();
	cout << "\n\nQ3 : " << q3 << endl;
	q3.solve();
	//Add and Subtract equations
	Quadratic q4 = q2 + q3;
	Quadratic q5 = q3 - q1;
	//Display the newly formed equations and their solutions using overloaded << operator
	cout << "\n\nq4 = q2 + q3" << endl << "q5 = q3 - q1" << endl;
	cout << "\n\nQ4 : " << q4 << endl;
	q4.solve();
	cout << "\n\nQ5 : " << q5 << endl;
	q5.solve();
}