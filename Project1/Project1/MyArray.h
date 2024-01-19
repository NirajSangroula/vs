#pragma once
template<typename T>
class MyArray
{
public:
	MyArray();
	~MyArray();
	void set(int i, T value);
	T get(int i);
	string toString();
private:
	int SIZE;
	T* myArrayPtr;
};

