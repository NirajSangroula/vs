#include "MyArray.h"
#include <string>
#include<sstream>
using namespace std;
template<typename T>
MyArray<T>::MyArray() {
	myArrayPtr = new T[SIZE];
}

template<class T>
MyArray<T>::~MyArray()
{
	delete myArrayPtr;
}

template<class T>
void MyArray<T>::set(int i, T value)
{
	(*myArrayPtr)[i] = value;
}

template<class T>
T MyArray<T>::get(int i)
{
	return (*myArrayPtr)[i];
}

template<class T>
string MyArray<T>::toString()
{
	ostringstream oss;
	for (T t : *myArrayPtr) {
		oss << t << ",";
	}
	return oss.str();
}
