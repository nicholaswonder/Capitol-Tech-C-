#include "Person.h"
#include <string>
#include <typeinfo>

using namespace std;

Person::Person()
{
	firstName = "";
	lastName = "";
	personID = 0;
	age = 0;
}

Person::Person(int newID, string newFirst, string newLast, int newAge) 
{
	// Create default values in case new values fail
	firstName = "";
	lastName = "";
	personID = 0;
	age = 0;

	// Use mutators to add given values
	setID(newID);
	setFirstName(newFirst);
	setLastName(newLast);
	setAge(newAge);
}

// Getters
int Person::getID()
{
	return personID;
}

string Person::getFullName()
{
	return firstName + " " + lastName;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

int Person::getAge()
{
	return age;
}

// Setters
void Person::setID(int newID)
{
	if (newID > 0) 
	{
		personID = newID;
	}
}

void Person::setFirstName(string newFirst)
{
	firstName = newFirst;
}

void Person::setLastName(string newLast)
{
	lastName = newLast;
}

void Person::setAge(int newAge)
{
	if (newAge > 0) 
	{
		age = newAge;
	}
}

// toString

string Person::toString()
{
	return "ID: " + to_string(getID()) + "\n" +
		"Name: " + getFullName() + "\n" +
		"Age: " + to_string(getAge()) + "\n";
}

// Equals
bool operator==(const Person& p1, const Person& p2)
{
	// Test if p1 and p2 are of the same class type

	if (typeid(p1) == typeid(p2)) 
	{
		return (p1.personID == p2.personID &&
			p1.firstName == p2.firstName &&
			p1.lastName == p2.lastName &&
			p1.age == p2.age);
	}
	else 
	{
		// If either are not of class Person, return false
		return false;
	}
}