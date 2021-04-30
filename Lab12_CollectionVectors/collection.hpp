//header for vector collection program
//Ian Zimmerman
//April 23, 2021

#include <vector>
#include <algorithm>

using std::vector;

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

int check (vector<double>&, double&); //checks if a number is in the collection
void addNumber (vector<double>&, double&); //adds a number to the collection
void removeNumber (vector<double>&, double&); //removes a number from the collection
void output (vector<double>&); //prints the contents of the collection

#endif // COLLECTION_HPP
