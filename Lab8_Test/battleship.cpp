//implementation of functions prototyped in battleship.hpp
//Ian Zimmerman
//March 19, 2021

#include "battleship.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout; using std::cin; using std::endl;

// ************************
// initialization functions
// ************************

//initialises every ship to (-1,*) to show it hasnt been deployed
void initialize(Ship boats[]) {
	for (int i = 0; i < fleetSize; ++i) {
		boats[i].loc.x = -1;
		boats[i].loc.y = '*';
		//cout << "DEV: boat " << i << " has been initialized to " << boats[i].loc.x << boats[i].loc.y << endl;
	}
}

//generates a random location
Location pick() {
	Location location; //returned to the calling function
	location.x = -1;
	location.y = '*';
	int tempNum = rand() % fieldSize + 1; //used to assign location.y
	
	location.x = rand() % fieldSize + 1;
	
	//takes the random number assigned to tempNum and correlates it to a letter value
	switch (tempNum) {
		case 1:
			location.y = 'a'; break;
		case 2:
			location.y = 'b'; break;
		case 3:
			location.y = 'c'; break;
		case 4:
			location.y = 'd'; break;
		case 5:
			location.y = 'e'; break;
		case 6:
			location.y = 'f'; break;
		//default:
			//cout << "DEV: pick() failed to assign location.y. It is currently " << location.y; break;
	}
	//cout << "DEV: the location leaving pick() is " << location.x << location.y << endl;
	return location;
}

//returns true if location is equal to boat.loc and returns false otherwise
bool match(const Ship& boat, const Location& location) {
	if ((location.x == boat.loc.x) && (location.y == boat.loc.y))
		return true;
	else return false;
}

//checks if a space is available for deploying/hitting a ship using match()
int check(const Ship boats[], const Location& location) {
	for (int i = 0; i < fleetSize; ++i) {
		if (match(boats[i], location)) {
			//cout << "DEV: ship " << i << " cannot be placed at " << location.x << location.y << endl;
			return i;
		}
	}
	return -1;
}

//places ships randomly in the ocean
void deploy(Ship boats[]) {
	int dep = 0; //number of deployed ships
	Location coords; //location of a placed ship

	//loops until it finds an open space to place a ship then moves to the next until a full fleet is out
	while (dep < fleetSize) {
		coords = pick();
		if (check(boats, coords) == -1) {
			boats[dep].loc.x = coords.x;
			boats[dep].loc.y = coords.y;
			boats[dep].sunk = false;
			dep = dep + 1;
		}
	}
}


// *****************
// display functions
// *****************

//prints the location and status of a single ship
void printShip(const Ship& boat) {
	cout << boat.loc.x << boat.loc.y;
	if (boat.sunk)
		cout << " sunk" << endl;
	else cout << " up" << endl;
}

//prints the location and status of every ship
void printFleet(const Ship boats[]) {
	for (int i = 0; i < fleetSize; ++i) 
		printShip(boats[i]);
}


// ****************
// battle functions
// ****************

//returns true if a ship remains unsunk
bool operational(const Ship boats[]) {
	int count = 0; //counts sunk ships
	for (int i = 0; i < fleetSize; ++i) {
		if (boats[i].sunk == true)
			count = count + 1;
		if (count == fleetSize)
			return false;
	}
	return true;
}

//gets the coordinates for the next shot from the user
Location fire() {
	Location coords; //stores user input
	
	cout << "Please input the x coordinate you would like to shoot (int 1-6): ";
	cin >> coords.x;
	cout << endl << "Please input the y coordinate you would like to shoot (char a-f): ";
	cin >> coords.y;
	cout << endl;

	return coords;
}

//updates the status of a sunken ship
void sink(Ship& boat) {
	boat.sunk = true;
}
