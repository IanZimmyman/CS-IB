//adds and removes numbers as inputed by the user
//Ian Zimmerman
//April 2, 2021

#include <iostream>
#include "collection.hpp"

using std::cout; using std::cin; using std::endl;

int main() {
	int size = 0; //size of the array
	double* ptr = new double[size]; //pointer to an array
	char choice = 'b'; //choice of opperation
	double number = 0.0; //input from user
	bool loop = true; //toggle to leave loop

	while (loop) {
		cout << "Please enter operation [a/r/q] and number: ";
		cin >> choice >> number;

		switch (choice) {
			case 'a':
				addNumber(ptr, number, size); break;
			case 'r':
				removeNumber(ptr, number, size); break;
			case 'q':
				loop = false; break;
			default:
				break;
		}

		cout << "Your numbers: ";
		output(ptr, size);
	}

	delete [] ptr;
}
