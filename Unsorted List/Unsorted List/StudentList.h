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

	// Add methods
	void addFront(Student newStudent);
	void append(Student newStudent);

	// Search method - returns index of found Student, -1 if not found
	int searchByID(int idToSearch);

	// Delete Methods
	void deleteByID(int idToDelete);
	void deleteByIndex(int indexToDelete);

	// toString
	std::string toString();

	// Destructor
	~StudentList();
};

#endif // !STUDENTLIST_H