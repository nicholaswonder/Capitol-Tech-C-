#include "Faculty.h"
#include <string>

using namespace std;

Faculty::Faculty() {
	firstName = "null";
	lastName = "null";
	tenure = false;
	officeNum = 0;
	next = nullptr;
}

Faculty::Faculty(string fName, string lName, bool tenure, short office) {
	setFirstName(fName);
	setLastName(lName);
	setTenure(tenure);
	setOfficeNum(office);
	next = nullptr;
}

// Getters

string Faculty::getFirstName() {
	return firstName;
}

string Faculty::getLastName() {
	return lastName;
}

bool Faculty::isTenured() {
	return tenure;
}

short Faculty::getOfficeNum() {
	return officeNum;
}

Faculty* Faculty::getNext() {
	return next;
}

// Setters

void Faculty::setFirstName(string newFName) {
	firstName = newFName;
}

void Faculty::setLastName(string newLName) {
	lastName = newLName;
}

void Faculty::setTenure(bool newTenure) {
	tenure = newTenure;
}

void Faculty::setOfficeNum(short newOffice) {
	if (newOffice > 0){
		officeNum = newOffice;
	}
}

void Faculty::setNext(Faculty* newNext) {
	next = newNext;
}

// toString

string Faculty::toString() {
	return getFirstName() + " " + getLastName() + "\n" +
		"Office Number: " + std::to_string(getOfficeNum()) + "\n" +
		"Is tenured: " + std::to_string(isTenured()) + "\n";
}