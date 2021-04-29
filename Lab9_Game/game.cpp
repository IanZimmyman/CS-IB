//main for the battleship game using classes
//Ian Zimmerman
//March 26, 2021

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	srand(time(nullptr)); // random seed
	Fleet myFleet;
	char print = 'n'; //choice for printing stats

	myFleet.deployFleet();

	cout << "Would you like to see the fleet stats? (y/n) ";
	cin >> print;

	//loops while at least one ship is still up
	while (myFleet.operational()) {
		Location userShot;
		userShot.fire();
		if (!myFleet.isHitNSink(userShot))
			cout << "Miss!" << endl;
		else cout << "Hit!" << endl;
		if (print == 'y')
			myFleet.printFleet();
	}
}
