//function definitions for those prototyped in collection.hpp
//Ian Zimmerman
//April 2, 2021

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

//prints the values in array colPtr of size
void output(double* colPtr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " ";
	}
	cout << endl;
}

//returns the index of the element in array colPtr of size
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(double* colPtr, double number, int size) {
	for (int i = 0; i < size; ++i) {
		if (colPtr[i] == number)
			return i;
	}
	return -1;
}

//adds num to the array pointed to by colPtr of size. 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased.
void addNumber(double*& colPtr, double number, int& size) {
	//call check() to see if number is in array already or not
	if (check(colPtr, number, size) != -1){
		cout << "That number already exists in the array." << endl;
		return;
	}

	//add number to the array
	else {
		double* ptr = new double[size + 1];
		for (int i = 0; i < size; ++i)
			ptr[i] = colPtr[i];
		size = size + 1;
		ptr[size - 1] = number;

		delete[] colPtr;
		colPtr = ptr;
	}
}

//removes a num from array colPtr of size.
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double*& colPtr, double number, int& size) {
	//call check() to see if its there
	int temp = check(colPtr, number, size);
	if (temp == -1) {
		cout << "That number does not exist in the array." << endl;
		return;
	}

	//remove number from array
	else {
		bool pastNum = false; //check if the index is past the number set to be removed
		double* ptr = new double[size - 1];
		for (int i = 0; i < size; ++i) {
			if (i == temp) {
				//ptr[i] = NULL;
				colPtr[i] = NULL;
				pastNum = true;
			}
			else if (pastNum)
				ptr[i - 1] = colPtr[i];
			else
				ptr[i] = colPtr[i];
		}
		size = size - 1;

		delete[] colPtr;
		colPtr = ptr;
	}
	//allocate a new memory block and copy all elements except "number" to the new array
	//double* ptr = new double[size - 1];

	//int i = 0;
	//for(;colPtr[i] != number; ++i)
}
