#ifndef TOOLS_H
#define TOOLS_H
#include<string>
class Tools
{
public:
	//Default constructor
	Tools() : record(0){
	}
	//Parameterised constructor
	Tools(int, std::string, int, double);
	//display function to print properties of tool
	void display() const;
	//Displays record number
	int getRecord();
private:
	int record;
	std::string toolName;
	int quantity;
	double cost;
};
#endif
