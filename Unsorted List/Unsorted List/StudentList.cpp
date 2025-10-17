#include "StudentList.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
StudentList::StudentList()
{
	head = nullptr;
}

// Add methods

// Add to front of list
void StudentList::addFront(Student newStudent)
{
	Student* newNode = new Student(newStudent);
	newNode->setNext(head);
	head = newNode;
}

// Append to end of list
void StudentList::append(Student newStudent)
{
	Student* newNode = new Student(newStudent);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	Student* temp = head;
	while (temp->getNext() != nullptr)
	{
		temp = temp->getNext();
	}
	temp->setNext(newNode);
}

// Search method - returns index of found Student, -1 if not found
int StudentList::searchByID(int idToSearch)
{
	Student* temp = head;
	int index = 0;
	while (temp != nullptr)
	{
		if (temp->getId() == idToSearch)
		{
			return index;
		}
		temp = temp->getNext();
		index++;
	}
	// Will only get here if not found
	return -1;
}

// Delete Methods
void StudentList::deleteByID(int idToDelete)
{
	// Check if list is empty
	if (head == nullptr)
	{
		cout << "List is empty. Cannot delete." << endl;
		return;
	}

	// Call searchByID to find index
	int indexToDelete = searchByID(idToDelete);
	if (indexToDelete == -1)
	{
		cout << "Student with ID " << idToDelete << " not found. Cannot delete." << endl;
		return;
	}

	// Call deleteByIndex
	deleteByIndex(indexToDelete);

}

void StudentList::deleteByIndex(int indexToDelete)
{
	// Check if list is empty
	if (head == nullptr)
	{
		cout << "List is empty. Cannot delete." << endl;
		return;
	}

	// Check if index is valid
	if (indexToDelete < 0)
	{
		cout << "Invalid index. Cannot delete." << endl;
		return;
	}

	// If deleting head
	if (indexToDelete == 0)
	{
		Student* temp = head;
		head = nullptr;
		delete temp;
		return;
	}

	// Traverse to the node before the one to delete
	Student* current = head;
	for (int i = 0; i < indexToDelete - 1; i++)
	{
		if (current->getNext() == nullptr)
		{
			cout << "Index out of bounds. Cannot delete." << endl;
			return;
		}
		current = current->getNext();
	}

	// Now current points to the node before the one to delete
	Student* nodeToDelete = current->getNext();
	if (nodeToDelete == nullptr)
	{
		cout << "Index out of bounds. Cannot delete." << endl;
		return;
	}
	// Bypass the node to delete
	current->setNext(nodeToDelete->getNext());

	// Delete the node
	delete nodeToDelete;
}

// Print method
string StudentList::toString()
{
	// Check if list is empty
	if (head == nullptr)
	{
		return "List is empty";
	}
	else
	{
		// Gather list contents
		Student* temp = head;
		string returnString = "";
		while (temp != nullptr)
		{
			returnString += temp->toString() + "\n";
			temp = temp->getNext();
		}
		return returnString;
	}
}

// Destructor
StudentList::~StudentList()
{
	Student* current = head;
	Student* next = nullptr;
	while (current != nullptr)
	{
		next = current->getNext();
		delete current;
		current = next;
	}
}