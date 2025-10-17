#pragma once
#include <string>

using namespace std;

class Person {
private:
	int personID;
	string firstName;
	string lastName;
	int age;

public:
	// Constructor
	Person();
	Person(int, string, string, int);

	// Getters
	int getID();
	string getFullName();
	string getFirstName();
	string getLastName();
	int getAge();

	// Setters
	void setID(int);
	void setFirstName(string);
	void setLastName(string);
	void setAge(int);

	// Equals
	friend bool operator==(const Person& p1, const Person& p2);

	// toString
	// made to be virtual to allow for overriding in derived classes
	virtual string toString();
};