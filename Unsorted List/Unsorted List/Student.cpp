#include "Student.h"

Student::Student() {
	id = 0;
	firstName = "";
	lastName = "";
	gpa = 0.0;
	studentStatus = UNKNOWN;
	next = nullptr;
}

Student::Student(int newId, std::string newFirstName, std::string newLastName, double newGpa, int newStatus) {
	id = 0;
	firstName = "";
	lastName = "";
	gpa = 0.0;
	studentStatus = UNKNOWN;
	next = nullptr;
	
	setId(newId);
	setFirstName(newFirstName);
	setLastName(newLastName);
	setGpa(newGpa);
	setStatus(newStatus);
}

// Getters
int Student::getId() {
	return id;
}

std::string Student::getFirstName() {
	return firstName;
}

std::string Student::getLastName() {
	return lastName;
}

double Student::getGpa() {
	return gpa;
}

Student::status Student::getStatus() {
	return studentStatus;
}

std::string Student::getStatusString() {
	switch (studentStatus) {
	case ACTIVE:
		return "Active";
	case GRADUATED:
		return "Graduated";
	case SUSPENDED:
		return "Suspended";
	default:
		return "Unknown";
	}
}

Student* Student::getNext() {
	return next;
}

// Setters
void Student::setId(int newId) {
	if (newId > 0) {
		id = newId;
	}
}

void Student::setFirstName(std::string newFirstName) {
	if (!newFirstName.empty()) {
		firstName = newFirstName;
	}
}

void Student::setLastName(std::string newLastName) {
	if (!newLastName.empty()) {
		lastName = newLastName;
	}
}

void Student::setGpa(double newGpa) {
	if (newGpa >= 0.0 && newGpa <= 4.0) {
		gpa = newGpa;
	}
}

void Student::setStatus(int newStatus) {
	switch (newStatus) {
	case 1:
		studentStatus = ACTIVE;
		break;
	case 2:
		studentStatus = GRADUATED;
		break;
	case 3:
		studentStatus = SUSPENDED;
		break;
	case 4:
		studentStatus = UNKNOWN;
		break;
	default:
		break;
	}
}

void Student::setNext(Student* nextStudent) {
	next = nextStudent;
}

// toString method
std::string Student::toString() {
	return "ID: " + std::to_string(id) + "\n" +
		"Name: " + firstName + " " + lastName + "\n" +
		"GPA: " + std::to_string(gpa) + "\n" + 
		"Year: " + getStatusString() + "\n";
}