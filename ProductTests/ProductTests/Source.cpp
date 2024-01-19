#include<iostream>
#include "Product.h"
using namespace std;
int main() {
	//Start a new Block
	{
		//Create two objects
		Product p1{ 4 }, p2{ 4 };
		cout << "Created p1 " << p1.toString() << " and p2 " << p2.toString() << endl;
		cout << "Count = ";
		//Display count after creating two products
		cout << Product::getCount()<<endl;
		//Change value of price
		p2.setPrice(43.55);
		cout << "New Price of p2 : $" << p2.getPrice() << endl;

		cout << "After the end of the block: " << endl;
	}
	//Display count after block ends or Products are destroyed
	cout << "\nAfter end of the block, count = ";
	cout << Product::getCount() << endl;
	//Create another product and display count
	Product p3{ 499 };
	cout << "After creating a product in main method, count = ";
	cout << Product::getCount() << endl;

	cout << "After the end of main block: ";
	return 0;
}