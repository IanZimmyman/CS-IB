//adds and removes from a collection using vectors
//Ian Zimmerman
//April 23, 2021

#include <iostream>
#include <vector>
#include <algorithm>
#include "collection.hpp"

using std::cout; using std::cin; using std::endl;
using std::vector;

int main() {
	//int size = 0; //size for vector col
	vector<double> col;//(size); //collection
	char choice = 'b'; //choice of opperation
	double number = 0.0; //input from user
	bool loop = true; //toggle to leave loop

	while (loop) {
		cout << "Please enter operation [a/r/q] and number: ";
		cin >> choice >> number;

		switch (choice) {
			case 'a':
				addNumber(col, number); break;
			case 'r':
				removeNumber(col, number); break;
			case 'q':
				loop = false; break;
			default:
				break;
		}

		cout << "Your numbers: ";
		output(col);
	}

	return 0;
}
