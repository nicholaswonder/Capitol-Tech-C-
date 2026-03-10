#include "Student.h"
#include "StudentList.h"
#include <iostream>
#include <string>

using namespace std;

int mainMenu()
{
	cout << "Student List Menu" << endl;
	cout << "1. Add new student" << endl;
	cout << "2. Search for student by ID" << endl;
	cout << "3. Delete student by ID" << endl;
	cout << "4. Print student list" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	do
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 5)
		{
			cin.clear(); // clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			choice = -1; // set choice to an invalid number
			cout << "Invalid input. Please enter a number between 1 and 5: ";
		}
	} while (choice < 1 || choice > 7);
	return choice;
}

Student createStudent()
{
	int id;
	string firstName;
	string lastName;
	double gpa;
	int statusInt;
	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		// Clears input stream
		cin.clear();												// Clears cin.fail flag
		cout << "Enter student ID: ";								// tells user what to unput
		cin >> id;													// take user input
	} while (cin.fail());											// Flag raises if there is an invalid input, like a char into an int and loops to retry input

	do																// Repeat for all inputs
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cout << "Enter first name: ";
		cin >> firstName;
	} while (cin.fail());

	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cout << "Enter last name: ";
		cin >> lastName;
	} while (cin.fail());

	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cout << "Enter GPA: ";
		cin >> gpa;
	} while (cin.fail());

	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cout << "Enter status (1: Active, 2: Graduated, 3: Suspended, 4: Unknown): ";
		cin >> statusInt;
	} while (cin.fail());

	Student newStudent(id, firstName, lastName, gpa, statusInt);
	return newStudent;
}

int main()
{
	int choice;
	int idToSearch;
	StudentList studentList;
	do
	{
		choice = mainMenu();
		switch (choice)
		{
		case 1:
		{
			Student newStudent = createStudent();
			Student* studentPtr = new Student(newStudent);
			studentList.add(studentPtr);
			break;
		}
		case 2:
		{
			cout << "Enter student ID to search: ";
			cin >> idToSearch;
			string result = studentList.searchForToString(idToSearch);
			cout << result << endl;
			break;
		}
		case 3:
		{
			cout << "Enter student ID to delete: ";
			cin >> idToSearch;
			studentList.deleteID(idToSearch);
			cout << "Student with ID " << idToSearch << " deleted." << endl;
			break;
		}
		case 4:
		{
			cout << "Student List:" << endl;
			cout << studentList.toString() << endl;
			break;
		}
		case 5:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 5);
}