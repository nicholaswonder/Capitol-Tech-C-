#include "FacultyList.h"
#include "Faculty.h"
#include <iostream>

FacultyList::FacultyList() {
	head = nullptr;
}

void FacultyList::addFirst(Faculty newFaculty) {
	Faculty* newNode = new Faculty(newFaculty); // Create pointer to new Faculty object
	newNode->setNext(head); // Set new node's next to current head
	head = newNode; // Update head to new node
}

void FacultyList::append(Faculty newFaculty) {
	Faculty* newNode = new Faculty(newFaculty); // Create pointer to new Faculty object
	if (head == nullptr) {
		head = newNode; // If list empty, set head to new node
	} else {
		Faculty* current = head; // Start at head
		while (current->getNext() != nullptr) {
			current = current->getNext(); // Traverse to end of list
		}
		current->setNext(newNode); // Set last node's next to new node
	}
}

void FacultyList::displayList() {
	Faculty* current = head; // Start at head
	if (current == nullptr) {
		std::cout << "The faculty list is empty." << std::endl;
		return;
	}
	while (current != nullptr) { // Iterate through list
		std::cout << current->toString() << std::endl; // Print current node's info
		current = current->getNext(); // Move to next node
	}
}

FacultyList::~FacultyList() {
	Faculty* current = head; // Start at head
	while (current != nullptr) { // Iterate through list
		Faculty* nextNode = current->getNext(); // Get next node
		delete current; // Delete current node
		current = nextNode; // Move to next node
	}
}