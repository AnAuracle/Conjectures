#include "Conjectures.h"

#include <iostream>

using namespace std;

int main() {
	string userIn = "";
	while (userIn != "-1") {
		cout << "Which conjecture would you like to play with?" << endl << "1 || Collatz Conjecture" << endl << endl << "2 || Goldbach Conjecture" << endl << endl << "3 || Twin Prime Conjecture" << endl << endl;
		while (userIn != "1" && userIn != "2" && userIn != "3") {
			cin >> userIn;
			if (userIn != "1" && userIn != "2" && userIn != "3") {
				cout << "Invalid Input" << endl;
			}
		}
		if (userIn == "1") {
			collatz();
		}
		else if (userIn == "2") {
			goldbach();
		}
		else if (userIn == "3") {
			twinprime();
		}
		cout << endl << "Would you like to see another conjecture? (y/n)" << endl;
		while (userIn != "y" && userIn != "n") {
			cin >> userIn;
			if (userIn != "y" && userIn != "n") {
				cout << "Invalid Input" << endl;
			}
		}
		if (userIn == "y") {
			userIn = "";
		}
		else {
			userIn = "-1";
		}
	}
	return 1;
}