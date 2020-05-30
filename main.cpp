#include "Entrance.cpp"
#include <iostream>
using namespace std;

int select(int &choice, int start, int end);

int main()
{
	Entrance e;
	e.Intro();

	return 0;
}

int select(int &choice, int start, int end) {	// validate choice
	// prompt user for choice
	cout << endl << "Select one of the options above\n>";
	cin >> choice;

	// if choice is invalid
	while(choice < start || choice > end || cin.fail()) {
		// reset cin
		cin.clear();
		cin.ignore(256,'\n');

		// prompt user to try again
		cout << "Invalid input! Try again\n>";
		cin >> choice;
	}
	// return validated choice
	return choice;
}
