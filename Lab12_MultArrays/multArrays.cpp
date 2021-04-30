//implementation of multArrays.hpp
//Ian Zimmerman
//April 23, 2021

#include <iostream>
#include "multArrays.hpp"

using std::cout; using std::cin; using std::endl;

//initializes the ocean array
void initialize (bool shots[][oceanWidth]) {
	for (int i = 0; i < oceanLength; ++i) {
		for (int j = 0; j < oceanWidth; ++j)
			shots[i][j] = false;
	}
}

//prints the current state of the ocean
void print (bool shots[][oceanWidth]) {
	for (int row = 0; row <= oceanLength; ++row) {
		for (int col = 0; col <= oceanWidth; ++col) {
			if (row == 0) {
				switch (col) {
					case 0: cout << " "; break;
					case 1: cout << "a"; break;
					case 2: cout << "b"; break;
					case 3: cout << "c"; break;
					case 4: cout << "d"; break;
					case 5: cout << "e"; break;
					case 6: cout << "f"; break;
				}
			}
			else if (col == 0) cout << row;
			else {
				if(!shots[row-1][col-1]) cout << "-";
				else cout << "*";
			}
			cout << " ";
		}
		cout << endl;
	}
}

//fires at a given location
void fire (bool shots[][oceanWidth], char row, int col) {
	int rowNum = -2;
	switch (row) {
		case 'a': rowNum = 0; break;
		case 'b': rowNum = 1; break;
		case 'c': rowNum = 2; break;
		case 'd': rowNum = 3; break;
		case 'e': rowNum = 4; break;
		case 'f': rowNum = 5; break;
		default: cout << "Please enter a valid row coordinate" << endl; break;
	}

	int temp = check(shots, rowNum, col);
	if (temp == -1)
		cout << "Duplicate: " << row << col << " has already been shot." << endl;
	else shots[col - 1][rowNum] = true;
	return;
}

//checks if a location has already been shot
int check (bool shots[][oceanWidth], int row, int col) {
	if (shots[col - 1][row] == true) return -1; //already been hit
	else return 1; //not hit yet
}
