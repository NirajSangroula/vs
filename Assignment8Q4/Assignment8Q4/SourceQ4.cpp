#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;
int main() {
	cout << "Enter the option:\n1 to search for words\n2 to add new words\n3 to view contents of the dictionary\n0 to quit the program\n";
	int n{ 0 };
	cin >> n;
	//Variables to store english word and translations
	string english{ "" }, translation{ "" };

	if (n == 2) {
		//Open dictionary file
		ofstream addDictionary{ "words.txt", ios::app };

		//exit program if unable to create file
		if (!addDictionary) {
			cerr << "File can't be opened.\n";
			exit(EXIT_FAILURE);
		}

		cout << "Enter english word and translation word for it: Ctrl-c to quit\n?";
		while (cin >> english >> translation) {
			addDictionary << english << " " << translation << endl;
			cout << "?";
		}
	}

	else if (n == 3) {
		//Open dictionary file
		ifstream allDictionary{ "words.txt", ios::in };
		//exit program if unable to create file
		if (!allDictionary) {
			cerr << "File can't be opened.\n";
			exit(EXIT_FAILURE);
		}

		cout << left <<setw(15) << "English word" << setw(15) << "Translation" << endl;
		while (allDictionary >> english >> translation) {
			cout << left << setw(15)  << english  << setw(15) << translation << endl;
		}
	}
	else if (n == 1) {
		cout << "Enter english word to search: \n";
		string word;
		cin >> word;
		//Open dictionary file
		ifstream allDictionary{ "words.txt", ios::in };
		//exit program if unable to create file
		if (!allDictionary) {
			cerr << "File can't be opened.\n";
			exit(EXIT_FAILURE);
		}
		while (allDictionary >> english >> translation) {
			//Display the translation if english matches the word searched
			if (english == word)
				cout << translation;
		}
	}

	return 0;
}