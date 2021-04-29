//implementation of functions from battleship.hpp
//Ian Zimmyman
//March 26, 2021

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;


// **************
// class Location
// **************

//initializes x_ to -1 and y_ to *
Location::Location() : x_(-1), y_('*') {}

//picks a random location
void Location::pick() {
	x_ = rand() % fieldSize_ + 1;
	switch (rand() % fieldSize_ + 1) {
		case 1:
			y_ = 'a'; break;
		case 2:
			y_ = 'b'; break;
		case 3:
			y_ = 'c'; break;
		case 4:
			y_ = 'd'; break;
		case 5:
			y_ = 'e'; break;
		case 6:
			y_ = 'f'; break;
		default:
			cout << "Something went wrong assigning y_" << endl; break;
	}
}

//takes user input for the next shot
void Location::fire() {
	cout << endl << "The y coordinate? (char a-f) ";
	cin >> y_;
	cout << endl << "The x coordinate? (int 1-6) ";
	cin >> x_;
	cout << endl;
}

//prints location in the format "a1"
void Location::print() const {
	cout << y_ << x_;
}

//friend function
//returns true if the two locations match
bool compare(const Location& loc1, const Location& loc2) {
	if ((loc1.x_ == loc2.x_) && (loc1.y_ == loc2.y_))
		return true;
	else return false;
}


// **********
// class Ship
// **********

//sets sunk_ to false
Ship::Ship() : sunk_(false) {}

//returns true if shot matches the ships location
bool Ship::match(const Location& shot) const {
	if (compare(loc_, shot))
		return true;
	else return false;
}

//sets sunk_ to true
void Ship::sink() {
	sunk_ = true;
}

//deploys a ship at the given location
void Ship::setLocation(const Location& coords) {
	loc_ = coords;
}

//prints location and status of a ship
void Ship::printShip() const {
	loc_.print();
	if (isSunk())
		cout << " sunk" << endl;
	else cout << " up" << endl;
}


// ***********
// class Fleet
// ***********

//places multiple ships
void Fleet::deployFleet() {
	Location coords;
	
	for (int dep = 0; dep < fleetSize_;) {
		coords.pick();
		if (check(coords) == -1) {
			ships_[dep].setLocation(coords);
			dep = dep + 1;
		}
	}
}

//returns true if at least one ship is still up
bool Fleet::operational() const {
	int sunkShips = 0; //counter for sunken ships

	for (int i = 0; i < fleetSize_; ++i) {
		if (ships_[i].isSunk())
			sunkShips = sunkShips + 1;
		if (sunkShips == fleetSize_)
			return false;
	}
	return true;
}

//returns true if hit and sinks, returns false if miss
bool Fleet::isHitNSink(const Location& shot) {
	for (int i = 0; i < fleetSize_; ++i) {
		int temp = check(shot);
		if (temp == -1)
			return false;
		else {
			ships_[temp].sink();
			return true;
		}
	}
}

//prints location and stats of all ships
void Fleet::printFleet() const{
	for (int i = 0; i < fleetSize_; ++i)
		ships_[i].printShip();
}

//returns index of ship if loc is occupied or -1
int Fleet::check(const Location& loc) const {
	for (int i = 0; i < fleetSize_; ++i) {
		if (ships_[i].match(loc))
			return i;
	}
	return -1;
}
