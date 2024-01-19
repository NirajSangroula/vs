#include "Tools.h"
#include<iomanip>
#include<iostream>
using namespace std;
Tools::Tools(int record, std::string tn, int qty, double c):record(record), toolName(tn), quantity(qty), cost(c)
{
}

void Tools::display() const
{
	cout << left << setw(10) << record << setw(15) << toolName << setw(10) << quantity << setw(15) << cost << endl;
}

int Tools::getRecord()
{
	return record;
}
