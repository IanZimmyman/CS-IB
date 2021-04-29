//adds and removes numbers from a collection
//Ian Zimmerman
//April 9, 2021

#include <iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl;

int main() {
	Collection col; //private members col_ and size_ both init to 0
	char choice = 'b'; //choice of opperation
	double number = 0.0; //input from user
	bool loop = true; //toggle to leave loop

	while (loop) {
		cout << "Please enter operation [a/r/q] and number: ";
		cin >> choice >> number;
		
		switch (choice) {
			case 'a':
				if (col.check(number) != -1)
					cout << "duplicate!" << endl;
				col.addNumber(number); break;
			case 'r':
				col.removeNumber(number); break;
			case 'q':
				loop = false; break;
			default:
				break;
		}

		cout << "Your numbers: ";
		col.output();
	}

}
