//implementation of class Collection
//Ian Zimmerman
//April 9, 2021

#include <iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl;

//void constructor
Collection::Collection() {
	col_ = 0;
	size_ = 0;
}


//returns index of element containg "number" or -1 if none
int Collection::check(double Num) {
	for (int i = 0; i < size_; ++i) {
		if (col_[i] == Num)
			return i;
	}
	return -1;
}

//adds number to the collection
void Collection::addNumber(double Num) {
	//call check() to see if number is in array already or not
	if (check(Num) != -1)
		return;

	//add number to the array
	else {
		double* ptr = new double[size_ + 1];
		for (int i = 0; i < size_; ++i)
			ptr[i] = col_[i];
		size_ = size_ + 1;
		ptr[size_ - 1] = Num;

		delete[] col_;
		col_ = ptr;
	}
}

//deletes the number from the collection
void Collection::removeNumber(double Num) {
	//call check() to see if its there
	int temp = check(Num);
	if (temp == -1)
		return;

	//remove number from array
	else {
		bool pastNum = false; //check if the index is past the number set to be removed
		double* ptr = new double[size_ - 1];
		for (int i = 0; i < size_; ++i) {
			if (i == temp) {
				col_[i] = NULL;
				pastNum = true;
			}
			else if (pastNum)
				ptr[i - 1] = col_[i];
			else
				ptr[i] = col_[i];
		}
		size_ = size_ - 1;

		delete[] col_;
		col_ = ptr;
	}
}

//prints the values of the collection
void Collection::output() {
	for (int i = 0; i < size_; ++i) {
		cout << col_[i] << " ";
	}
	cout << endl;
}

//copy constructor
Collection::Collection(const Collection& Col) {
	col_ = new double[Col.size_];
	size_ = Col.size_;
	for (int i = 0; i < size_; ++i)
		col_[i] = Col.col_[i];
}

//overloaded assignment
Collection& Collection::operator=(const Collection& Col) {
	if (this != &Col) {
		if (size_ > 0)
			delete[] col_;

		col_ = new double[Col.size_];
		size_ = Col.size_;
		for (int i = 0; i < size_; ++i)
			col_[i] = Col.col_[i];
	}

	return *this;
}

//destructor
Collection::~Collection() {
	delete[] col_;
}
