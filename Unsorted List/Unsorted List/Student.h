#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student
{
public:
	enum status { ACTIVE, GRADUATED, SUSPENDED, UNKNOWN };

	// Constructors
	Student();
	Student(int newId, std::string newFirstName, std::string newLastName, double newGpa, int newStatus);

	// Getters
	int getId();
	std::string getFirstName();
	std::string getLastName();
	double getGpa();
	status getStatus();
	// Returns the year as a string
	std::string getStatusString();
	Student* getNext();

	// Setters
	void setId(int newId);
	void setFirstName(std::string newFirstName);
	void setLastName(std::string newLastName);
	void setGpa(double newGpa);
	void setStatus(int newStatus);
	void setNext(Student* nextStudent);

	// toString method
	std::string toString();

	// Had to put private at the bottom because of the enum. It wasnt able to define 'year' otherwise
private:
	int id;
	std::string firstName;
	std::string lastName;
	double gpa;
	status studentStatus;

	Student* next; // Pointer to the next student in the list

};

#endif // !STUDENT_H