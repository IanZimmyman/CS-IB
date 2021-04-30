//implementation of collection.hpp
//Ian Zimmerman
//April 23, 2021

#include <iostream>
#include <vector>
#include <algorithm>
#include "collection.hpp"

using std::cout; using std::cin; using std::endl; using std::vector;

//checks if a number is in the collection
int check (vector<double>& col, double& num) {
	for (size_t i = 0; i < col.size(); ++i) {
		if (col[i] == num)
			return i;
	}
	return -1;
}

//adds a number to the collection
void addNumber (vector<double>& col, double& num) {
	if (check(col, num) == -1)
		col.push_back(num);
	else cout << "Duplicate!" << endl;
}

//removes a number from the collection
void removeNumber (vector<double>& col, double& num) {
	//int temp = check(col,num); //checks if num is in col, stores in temp
	if (check(col, num) == -1) {
		cout << num << " is not in the collection." << endl;
		return;
	}
	else {
		col.erase(col.begin() + (check(col, num)));
	}
}

//prints the contents of the collection
void output (vector<double>& col) {
	for (size_t i = 0; i < col.size(); ++i)
		cout << col[i] << " ";
	cout << endl;
}
