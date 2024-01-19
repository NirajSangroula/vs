#include<iostream>
using namespace std;
class A {

public:

    int count{ 0 };

};

void increment(A obj, int& t) {

    obj.count++;

    t++;

}

int main() {

    A a;

    int times{ 0 };

    increment(a, times);

    cout << a.count << endl;

    cout << times << endl;

}