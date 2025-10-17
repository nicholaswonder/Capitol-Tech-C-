#include "Faculty.h"
#include "FacultyList.h"
#include <iostream>

using namespace std;

int main()
{
	// Initialize variables to hold user input
	string fName, lName;
	bool tenure;
	short office;

	// Create a standard array to hold 5 Faculty objects
	Faculty facultyArray[5];

	// Gather user input to populate the Faculty objects in the array
	for (int i = 0; i < 5; i++) {
		cout << "Enter first name of faculty member " << (i + 1) << ": ";
		cin >> fName;
		cout << "Enter last name of faculty member " << (i + 1) << ": ";
		cin >> lName;
		cout << "Is the faculty member tenured? (1 for yes, 0 for no): ";
		cin >> tenure;
		cout << "Enter office number of faculty member " << (i + 1) << ": ";
		cin >> office;
		facultyArray[i] = Faculty(fName, lName, tenure, office);
	}

	// Display the information of each faculty member in standard array
	for (int i = 0; i < 5; i++) {
		cout << facultyArray[i].toString() << endl;
	}

	// Begin linked list testing
	// Create a FacultyList object
	FacultyList facultyList;

	// Show that the list is initially empty
	cout << "Before filling dynamic memory" << endl;
	facultyList.displayList();
	cout << endl;

	// Add each Faculty object from the array to the linked list
	// I used the same 5 from the array because user input is annoying
	for (int i = 0; i < 5; i++) {
		facultyList.append(facultyArray[i]);
	}

	// Display the linked list
	facultyList.displayList();



	return 0;
}