//plays battleship
//Ian Zimmerman
//March 19, 2021

#include "battleship.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout; using std::cin; using std::endl;

int main() {
	// **************
	// setup for game
	// **************

	srand(time(nullptr)); //random seed

	int temp = 0; //used to sink ships

	Location loc; //coordinate the user will shoot
	loc.x = 4;
	loc.y = 'f';

	Ship fleet[fleetSize];

	initialize(fleet); //initializes array
	deploy(fleet); //assigns random x and y values
	//printFleet(fleet);

	// ***********
	// game starts
	// ***********
	
	//loops while at least one ship is still afloat
	while (operational(fleet) == true) {
		loc = fire();
		temp = check(fleet, loc);
		if (temp != -1) {
			sink(fleet[temp]);
			cout << "Hit. Ship " << temp << " was sunk at " << loc.x << loc.y << endl;
		}
		else
			cout << "Miss." << endl;
		printFleet(fleet);
	}
}
