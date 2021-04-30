//plays a dumbed down battleship using multidimensional arrays
//Ian Zimmerman
//April 23,2021

#include <iostream>
#include "multArrays.hpp"

using std::cout; using std::cin; using std::endl;

int main () {
	bool shots[oceanLength][oceanWidth]; //ocean array
	int col = -1; //part of target coord
	char row = 'p'; //part of target coord
	char choice = 'p'; //choice to continue
	bool cont = true; //continues loop
	bool choose = true; //forces a correct choice for continue


	initialize(shots);
	print(shots);

	while (cont) {
		cout << "Enter coordinates to fire in the form (a 1) ";
		cin >> row >> col;
		cout << endl;

		fire(shots, row, col);
		print(shots);

		while (choose) {
			cout << "Would you like to take another shot? (y/n) ";
			cin >> choice;
			if (choice == 'n') {
				cont = false;
				choose = false;
			}
			else if (choice == 'y') {
				cont = true;
				choose = false;
			}
			cout << endl;
		}
		choose = true;
	}

	return 0;
}
