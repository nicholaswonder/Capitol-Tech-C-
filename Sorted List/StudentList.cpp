#pragma once
#ifndef STUDENTLIST_CPP
#define STUDENTLIST_CPP

#include "StudentList.h"

StudentList::StudentList() {
	head = nullptr;
}

void StudentList::add(Student* newStudent) {
	if (head == nullptr || newStudent->getId() < head->getId()) {
		newStudent->setNext(head);
		head = newStudent;
		return;
	}
	Student* current = head;
	while (current->getNext() != nullptr && current->getNext()->getId() < newStudent->getId()) {
		current = current->getNext();
		if (current->getId() == newStudent->getId()) {
			// Duplicate ID found, do not add
			return;
		}
	}
	newStudent->setNext(current->getNext());
	current->setNext(newStudent);
}

int StudentList::searchForIndex(int idToSearch) {
	Student* current = head;
	int index = 0;
	while (current != nullptr) {
		if (current->getId() == idToSearch) {
			return index;
		}
		current = current->getNext();
		index++;
	}
	return -1;
}

std::string StudentList::searchForToString(int idToSearch) {
	Student* current = head;
	while (current != nullptr) {
		if (current->getId() == idToSearch) {
			return current->toString();
		}
		current = current->getNext();
	}
	return "Student not found.";
}

void StudentList::deleteID(int idToDelete) {
	if (head == nullptr) {
		return;
	}
	if (head->getId() == idToDelete) {
		Student* toDelete = head;
		head = head->getNext();
		delete toDelete;
		return;
	}
	Student* current = head;
	while (current->getNext() != nullptr && current->getNext()->getId() != idToDelete) {
		current = current->getNext();
	}
	if (current->getNext() != nullptr) {
		Student* toDelete = current->getNext();
		current->setNext(toDelete->getNext());
		delete toDelete;
	}
}

std::string StudentList::toString() {
	std::string result;
	Student* current = head;
	while (current != nullptr) {
		result += current->toString() + "\n";
		current = current->getNext();
	}
	return result;
}

StudentList::~StudentList() {
	Student* current = head;
	while (current != nullptr) {
		Student* toDelete = current;
		current = current->getNext();
		delete toDelete;
	}
}

#endif // !STUDENTLIST_CPP
