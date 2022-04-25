#pragma once
#include <iostream>
#include <string>

using namespace std;

class Conjectures {
public:
	void Conjmain();
private:
	bool isValidNum(string x);
	int menu();
	bool primeTest(int x);
	int findPrime(int x);
	bool endMenu();
	void collatz(int x);
	void collatz();
	void goldbach();
	void twinprime();
	void twinprime(int x);
};

bool Conjectures::isValidNum(string x) {
	bool valid = true;
	for (unsigned int i = 0; i < x.length(); i++) {
		if (!isdigit(x.at(i))) {
			valid = false;
			break;
		}
	}
	return valid;
}

int Conjectures::menu() {
	string userIn = "";
	cout << "Which number would you like to try?" << endl << endl;
	cin >> userIn;
	while (!isValidNum(userIn)) {
		cout << "Invalid number" << endl;
		cin >> userIn;
	}
	return stoi(userIn);
}

bool Conjectures::primeTest(int x) {
	if (x == 0 || x == 1) {
		return false;
	}
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int Conjectures::findPrime(int x) {
	int i = x-1;
	while (!primeTest(i)) {
		i--;
	}
	return i;
}

bool Conjectures::endMenu() {
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

void Conjectures::collatz(int x) {
	cout << x << endl;
	if (x == 1) {
		return;
	}
	if ((x % 2) == 0) {
		x = x / 2;
	}
	else {
		x = (x * 3) + 1;
	}
	collatz(x);
}

void Conjectures::collatz() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		cout << "Collatz Conjecture Beginning With: " << testVal << endl << "==========================" << endl;
		collatz(testVal);
		loopBool = endMenu();
	}
}

void Conjectures::goldbach() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		if (testVal < 4) {
			cout << "Too small for conjecture" << endl;
			break;
		}
		if ((testVal % 2) != 0) {
			cout << "Adding 1 to make value even..." << endl;
			testVal++;
		}

		int prime = findPrime(testVal);
		cout << testVal << " is the sum of primes: " << endl << "======================" << endl;
		
		while (prime >= testVal/2) {
			if (primeTest(testVal - prime)) {
				cout << "{" << prime << "," << (testVal - prime) << "}" << endl;
			}
			prime = findPrime(prime);
		}
		
		loopBool = endMenu();
	}
}

void Conjectures::twinprime() {
	bool loopBool = true;
	while (loopBool == true) {
		int testVal = menu();
		if (testVal < 5) {
			cout << "There are no twin primes below this value" << endl;
			return;
		}
		else if (primeTest(testVal)) {
			break;
		}
		else {
			testVal = findPrime(testVal);
		}
		twinprime(testVal);
		loopBool = endMenu();
	}
}

void Conjectures::twinprime(int x) {
	if (primeTest(x - 2)) {
		cout << "Nearest Twin Primes: {" << x - 2 << "," << x << "}" << endl;
		return;
	}
	twinprime(findPrime(x));
}

void Conjectures::Conjmain() {
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
}
