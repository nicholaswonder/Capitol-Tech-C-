#include "Professor.h"
#include <string>

using namespace std;

Professor::Professor() {
	firstName = "null";
	lastName = "null";
	tenure = false;
	officeNum = 0;
}

Professor::Professor(string fName, string lName, bool tenure, short office) {
	setFirstName(fName);
	setLastName(lName);
	setTenure(tenure);
	setOfficeNum(office);
}

// Getters

string Professor::getFirstName() {
	return firstName;
}

string Professor::getLastName() {
	return lastName;
}

bool Professor::isTenured() {
	return tenure;
}

short Professor::getOfficeNum() {
	return officeNum;
}

// Setters

void Professor::setFirstName(string newFName) {
	firstName = newFName;
}

void Professor::setLastName(string newLName) {
	lastName = newLName;
}

void Professor::setTenure(bool newTenure) {
	tenure = newTenure;
}

void Professor::setOfficeNum(short newOffice) {
	if (newOffice > 0){
		officeNum = newOffice;
	}
}

// toString

string Professor::toString() {
	return getFirstName() + " " + getLastName() + "\n" +
		"Office Number: " + std::to_string(getOfficeNum()) + "\n" +
		"Is tenured: " + std::to_string(isTenured());
}