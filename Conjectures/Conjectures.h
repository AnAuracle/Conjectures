#pragma once
#include <iostream>
#include <string>

using namespace std;

bool isValidNum(string x) {
	bool valid = true;
	for (unsigned int i = 0; i < x.length(); i++) {
		if (!isdigit(x.at(i))) {
			valid = false;
			break;
		}
	}
	return valid;
}

int menu() {
	string userIn = "";
	cout << "Which number would you like to try?" << endl << endl;
	cin >> userIn;
	while (!isValidNum(userIn)) {
		cout << "Invalid number" << endl;
		cin >> userIn;
	}
	return stoi(userIn);
}

bool endMenu() {
	string userIn;
	cout << endl << "Would you like to try another number? (y/n)" << endl;
	while (userIn != "y" && userIn != "n") {
		cin >> userIn;
		if (userIn != "y" && userIn != "n") {
			cout << "Invalid Input" << endl;
		}
	}
	if (userIn == "y") {
		return true;
	}
	else {
		return false;
	}
}


void collatz() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		//run recursion
		loopBool = endMenu();
	}
}

void goldbach() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		//run recursion
		loopBool = endMenu();
	}
}

void twinprime() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		//run recursion
		loopBool = endMenu();
	}
}