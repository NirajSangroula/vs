//Program to display mean, median, standard deviation, min and max of the given sequence
#include<iostream>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
	//Read sequence of numbers from user and store in vector
	cout << "Enter no of items in sequence : ";
	int n;
	cin >> n;
	cout << "Enter a sequence of numbers \n";
	//Declaring a vector of double type with n elements
	vector<double> numbers(n);
	for (double &number : numbers) {
		//Read each numbers and store in numbers vector
		cin >> number;
	}
	//To calculate sum of the sequence of numbers
	double sum{ 0 };
	for (double number : numbers) {
		sum += number;
	}	
	//Mean = Sum of elements / No of elements
	double mean = sum / n;

	//Vector to store sorted numbers in ascending order
	vector<double> sorted(n);
	//Copy unsorted values to sorted vector
	for (int i = 0; i < n; i++) {
		sorted[i] = numbers[i];
	}

	//Sort sorted vector
	for (int i{ 0 }; i < n - 1; i++) {
		double smallest = sorted[i];
		for (int j{ i + 1 }; j < n; j++) {
			if (sorted[j] < sorted[i]) {
				double temp = sorted[j];
				sorted[j] = sorted[i];
				sorted[i] = temp;
			}

		}
	}

	//If n is odd, median is (n + 1)/ 2 th element, otherwise, (Sum of n/2 th and n/2 +1 th element / 2 : Note we subtract 1 because vector index starts with 0
	double median = (n % 2 == 1) ? sorted[((n + 1) / 2) - 1] : ((sorted[n / 2 - 1] + sorted[n / 2 + 1 - 1]) / 2);

	//Sum of deviation = Sum of all (x - mean)^2
	double sumOfDeviation{ 0 };
	for (int i = 0; i < n; i++) {
		sumOfDeviation += pow((numbers[i] - mean), 2);
	}

	//Standard Deviation = SquareRoot(Sum of all(x - mean)^2 / n)
	double standardDeviation = sqrt(sumOfDeviation / n);

	//Initally let min is first element
	double min{ numbers[0] };
	//Assign to min if any element is smaller than current min
	for (double number : numbers) {
		if (number < min)
			min = number;
	}

	//Initially let max is first element
	double max{ numbers[0] };
	//Assign to max if any element is greater than current max
	for (double number : numbers) {
		if (number > max)
			max = number;
	}

	//Display mean, median, standard deviation, min and max
	cout << "Mean : " << fixed << setprecision(2) << mean << endl;
	cout << "Median : " << median << endl;
	cout << "Standard deviation : " << standardDeviation << endl;
	cout << "Min : " << min << " Max : " << max << endl;
	return 0;
}