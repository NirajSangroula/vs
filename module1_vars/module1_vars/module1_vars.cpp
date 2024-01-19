#include<iostream>
#include<array>
using namespace std;
const size_t SIZE{ 20 };
bool contains(array<int, SIZE> a, int number);
int main() {
    //Declare array to store 20 numbers
    array<int, SIZE> numbers{};
    //Count of total valid numbers entered
    size_t n{ 0 };
    cout << "Enter 20 unique numbers between 10 and 100 inclusive\n";
    //Read 20 numbers
    for (size_t i{ 1 }; i <= SIZE; i++) {
        //Read a temporary number
        int temp{ 0 };
        cin >> temp;
        //Store the temp in the array only if it is valid i.e is between 10 and 100 inclusive and is not contained in array
        if (temp >= 10 && temp <= 100 && !contains(numbers, temp)) {
            numbers[n++] = temp;
        }
    }
    //Display all values stored in array
    cout << "\n\nThe numbers stored in array are: \n";
    for (int i{ 0 }; i < n; i++) {
        cout << numbers[i] << "\t";
    }
    return 0;
}
//Param array<int, 20> a , int number
//Checks if the given number is in array
bool contains(array<int, SIZE> a, int number) {
    for (auto value : a)
        if (value == number)
            return true;
    return false;
}
