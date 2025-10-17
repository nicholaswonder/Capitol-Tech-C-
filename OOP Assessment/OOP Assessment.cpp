#include <iostream>
#include <string>
#include <list>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

Person newPerson();
Student newStudent();
Faculty newFaculty();

int main()
{
	short input = 0;
	list<Person> personList;
	list<Student> studentList;
	list<Faculty> facultyList;

    // Main Menu
	while (input != 3)
	{
		cout << "Main Menu\n";
		cout << "1. Add\n";
		cout << "2. Display\n";
		cout << "3. Exit\n";
		cout << "Enter choice: ";
		cin >> input;
		switch (input)
		{
		case 1:
			// Add new entry

			while (input != 4)
			{
				cout << "Add Menu\n";
				cout << "1. Person\n";
				cout << "2. Student\n";
				cout << "3. Faculty\n";
				cout << "4. Return to Main Menu\n";
				cout << "Enter choice: ";
				cin >> input;
				switch (input)
				{
				case 1:
					// Add Person
					personList.push_back(newPerson());
					cout << "Person added successfully.\n";
					break;
				case 2:
					// Add Student
					studentList.push_back(newStudent());
					cout << "Student added successfully.\n";
					break;
				case 3:
					// Add Faculty
					facultyList.push_back(newFaculty());
					cout << "Faculty added successfully.\n";
					break;
				case 4:
					// Return to Main Menu
					cout << "Returning to Main Menu.\n";
					break;
				default:
					cout << "Invalid choice. Please try again.\n";
					break;
				}
				input = 0;
				break;
		case 2:
			// Display
			cout << "Displaying all entries:\n\n";
			cout << "Persons:\n";
			for (Person p : personList)
			{
				cout << p.toString() << "\n";
			}
			cout << "Students:\n";
			for (Student s : studentList)
			{
				cout << s.toString() << "\n";
			}
			cout << "Faculty:\n";
			for (Faculty f : facultyList)
			{
				cout << f.toString() << "\n";
			}
			input = 0;
			break;
		case 3:
			// Exit
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
			}
		}

	}
	return 0;
}

Person newPerson()
{
	int pID, pAge;
	string pFirst, pLast;
	cout << "Enter Person ID: ";
	cin >> pID;
	cout << "Enter First Name: ";
	cin >> pFirst;
	cout << "Enter Last Name: ";
	cin >> pLast;
	cout << "Enter Age: ";
	cin >> pAge;
	return Person(pID, pFirst, pLast, pAge);
}

Student newStudent()
{
	int sID, sAge, sYear;
	float sGPA;
	string sFirst, sLast;
	cout << "Enter Student ID: ";
	cin >> sID;
	cout << "Enter First Name: ";
	cin >> sFirst;
	cout << "Enter Last Name: ";
	cin >> sLast;
	cout << "Enter Age: ";
	cin >> sAge;
	cout << "Enter GPA: ";
	cin >> sGPA;
	cout << "Enter Year (0-Freshman, 1-Sophomore, 2-Junior, 3-Senior): ";
	cin >> sYear;
	return Student(sID, sFirst, sLast, sAge, sGPA, sYear);
}

Faculty newFaculty()
{
	int fID, fAge, fYears, fOffice;
	string fFirst, fLast, fRank;
	cout << "Enter Faculty ID: ";
	cin >> fID;
	cout << "Enter First Name: ";
	cin >> fFirst;
	cout << "Enter Last Name: ";
	cin >> fLast;
	cout << "Enter Age: ";
	cin >> fAge;
	cout << "Enter Rank: ";
	cin >> fRank;
	cout << "Enter Years of Service: ";
	cin >> fYears;
	cout << "Enter Office Number: ";
	cin >> fOffice;
	return Faculty(fID, fFirst, fLast, fAge, fRank, fYears, fOffice);
}