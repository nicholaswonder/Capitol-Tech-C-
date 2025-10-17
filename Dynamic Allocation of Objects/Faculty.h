#pragma once
#include <string>

using namespace std;

class Faculty
{
private:
	string firstName;
	string lastName;
	bool tenure;
	short officeNum;
	Faculty* next; // Pointer to the next Faculty object in the linked list

public:
	// Constructors
	Faculty();
	Faculty(string, string, bool, short);

	// Getters
	string getFirstName();
	string getLastName();
	bool isTenured();
	short getOfficeNum();
	Faculty* getNext(); // Getter for the next pointer

	// Setters
	void setFirstName(string);
	void setLastName(string);
	void setTenure(bool);
	void setOfficeNum(short);
	void setNext(Faculty*); // Setter for the next pointer

	// toString
	string toString();
};