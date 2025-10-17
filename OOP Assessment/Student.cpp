#include "Student.h"
#include <typeinfo>

// Constructors
Student::Student() : Person()
{
	gpa = 0.0;
	year = FRESHMAN;
}

Student::Student(int newID, string newFirst, string newLast, int newAge, float newGPA, int newYear) : Person(newID, newFirst, newLast, newAge)
{
	gpa = 0.0;
	year = FRESHMAN;
	setGPA(newGPA);
	setYear(newYear);
}

// Getters

int Student::getYear()
{
	return year;
}

float Student::getGPA()
{
	return gpa;
}

// Setters

void Student::setYear(int newYear)
{
	if (newYear >= FRESHMAN && newYear <= SENIOR)
	{
		year = static_cast<Year>(newYear);
	}
}

void Student::setGPA(float newGPA)
{
	if (newGPA >= 0.0 && newGPA <= 4.0)
	{
		gpa = newGPA;
	}
}

// toString override
string Student::toString()
{
	return Person::toString() + 
		"GPA: " + to_string(gpa) + "\n" + 
		"Year: " + to_string(getYear()) + "\n";
}

// Equals override
bool operator==(const Student& s1, const Student& s2)
{
	// Test if s1 and s2 are of same class

	if (typeid(s1) == typeid(s2))
	{
		// static casting to Person to compare Person attributes
		return (static_cast<Person>(s1) == static_cast<Person>(s2)) && (s1.gpa == s2.gpa) && (s1.year == s2.year);
	}
	else
	{
		// If not both Students, return false
		return false;
	}
}