//function prototypes for boof battleship
//Ian Zimmerman
//April 23, 2021

#ifndef MULTARRAYS_HPP_
#define MULTARRAYS_HPP_

//size of the ocean
const int oceanLength = 6;
const int oceanWidth = 6;

//function prototypes
void initialize (bool[][oceanWidth]); //initializes the ocean array
void print (bool[][oceanWidth]); //prints the current state of the ocean
void fire(bool[][oceanWidth], char, int); //fires at a given location
int check(bool[][oceanWidth], int, int); //checks if a location has already been shot

#endif //MULTARRAYS_HPP_
