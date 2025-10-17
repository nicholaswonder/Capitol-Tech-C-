#pragma once
#include "Faculty.h"

class FacultyList
{
private:
	Faculty* head; // Pointer to the head of the linked list

public:
	// Constructor
	FacultyList();

	// Add to top
	void addFirst(Faculty);

	// Append to end
	void append(Faculty);

	// Display list
	void displayList();

	// Destructor
	~FacultyList();
};