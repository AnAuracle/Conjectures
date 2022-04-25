#include "Conjectures.h"

#include <iostream>
#include <stack>

using namespace std;

void doPush(stack<int> &s1) {
	string numIn;
	cout << "What would you like to add?" << endl;
	cin >> numIn;
	//I didn't check to see if the input was actually a number, so don't put a character in your input (please :D)
	s1.push(stoi(numIn));
}
void doPop(stack<int>& s1) {
	stack<int> s2;
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
	while (!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
}

int doTop(stack<int>& s1) {
	stack<int> s2;
	int numOut;
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	numOut = s2.top();
	while (!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	return numOut;
}

void stacksasqueue() {
	stack<int> s1;
	string userIn;
	for (int i = 0; i < 10; i++) {
		cout << "What would you like to do to your queue? (1: push, 2: pop, 3: front)" << endl;
		cin >> userIn;
		bool valid = true;
		for (unsigned int i = 0; i < userIn.length(); i++) {
			if (!isdigit(userIn.at(i))) {
				valid = false;
				break;
			}
		}
		if (valid == false) {
			cout << "Invalid input, try again!";
		}
		switch (stoi(userIn)) {
		case 1:
			doPush(s1);
			break;
		case 2:
			doPop(s1);
			break;
		case 3:
			cout << "Queue front: " << doTop(s1) << endl;
		}
		
	}
	while (!s1.empty()) {
		cout << s1.top() << ", ";
		s1.pop();
	}
	cout << endl;
}


int main() {
	string userIn;
	cout << "Would you like to play with mathematical conjectures or use stacks to make a queue? (1 for conjectures, 2 for queue since it rhymes)" << endl;
	cin >> userIn;
	bool valid = true;
	for (unsigned int i = 0; i < userIn.length(); i++) {
		if (!isdigit(userIn.at(i))) {
			valid = false;
			break;
		}
	}
	if (valid == false) {
		cout << "Invalid input, try again!";
	}
	else if (stoi(userIn) == 1) {
		Conjectures conj;
		conj.Conjmain();
	}
	else if (stoi(userIn) == 2) {
		stacksasqueue();
	}
	else {
		cout << "Invalid input, try again!";
	}

	
	return 1;
}

