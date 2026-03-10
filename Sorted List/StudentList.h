#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <string>

class StudentList
{
private:
	Student* head;

public:
	StudentList();

	// Add method - only need one since list is sorted by ID
	void add(Student* newStudent);

	// Search method - returns index of found Student, -1 if not found
	int searchForIndex(int idToSearch);

	// Another search method, but returns a students toString if found
	std::string searchForToString(int idToSearch);

	// Delete Method
	void deleteID(int idToDelete);

	// toString
	std::string toString();

	// Destructor
	~StudentList();
};

#endif // !STUDENTLIST_H