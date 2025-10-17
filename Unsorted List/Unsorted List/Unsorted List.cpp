#include <iostream>
#include <string>
#include "StudentList.h"

using namespace std;

int mainMenu()
{
	cout << "Student List Menu" << endl;
	cout << "1. Add new student to front" << endl;
	cout << "2. Append new student to end" << endl;
	cout << "3. Search for student by ID" << endl;
	cout << "4. Delete student by ID" << endl;
	cout << "5. Delete student by index" << endl;
	cout << "6. Print student list" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	do
	{
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 7)
		{
			cin.clear(); // clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			choice = -1; // set choice to an invalid number
			cout << "Invalid input. Please enter a number between 1 and 7: ";
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
	StudentList list;

	do
	{
		choice = mainMenu();
		switch (choice)
		{
		case 1:
			// Add new student to front
			list.addFront(createStudent());
			break;
		case 2:
			// Append new student to end
			list.append(createStudent());
			break;
		case 3:
			// Search by ID number
			cout << "Enter ID to search: ";
			cin >> idToSearch;
			idToSearch = list.searchByID(idToSearch); // Reusing variable to store index
			if (idToSearch != -1)
			{
				cout << "Student found at index: " << idToSearch << endl;
			}
			else
			{
				cout << "Student not found." << endl;
			}
			break;
		case 4:
			// Delete by ID number
			cout << "Enter ID to delete: ";
			cin >> idToSearch;
			list.deleteByID(idToSearch);
			break;
		case 5:
			// Delete by index
			int indexToDelete;
			cout << "Enter index to delete: ";
			cin >> indexToDelete;
			list.deleteByIndex(indexToDelete);
			break;
		case 6:
			// Print student list
			cout << list.toString() << endl;
			break;
		case 7:
			// Exit
			cout << "Exiting program." << endl;
			break;
		default:
			// Should never get here
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 7);
}
