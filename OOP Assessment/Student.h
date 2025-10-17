#pragma once
#include "Person.h"

// Making enum equivalent to int values for easier setting and getting
enum Year { FRESHMAN = 1, SOPHOMORE = 2, JUNIOR = 3, SENIOR = 4 };

class Student : public Person
{
private:
	Year year;
	float gpa;

public:
	// Constructor
	Student();
	Student(int, string, string, int, float, int);

	// Getter
	int getYear();
	float getGPA();

	// Setter
	void setYear(int);
	void setGPA(float);

	// toString
	string toString() override;

	// Equals
	friend bool operator==(const Student& s1, const Student& s2);
};