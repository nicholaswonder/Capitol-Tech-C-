#ifndef CLIENTLIST_CPP
#define CLIENTLIST_CPP
#include "ClientList.h"
#include <string>

// Constructor + Destructor
ClientList::ClientList()
{
	head = nullptr;
}

ClientList::~ClientList()
{
	Client* current = head;
	while (current != nullptr)
	{
		Client* toDelete = current;
		current = current->getNext();
		delete toDelete;
	}
}

// Add client - will sort clients as they are added with insertion sort.
void ClientList::addClient(Client* newClient)
{
	if (head == nullptr || newClient->getAccountID() < head->getAccountID())
	{
		newClient->setNext(head);
		head = newClient;
		return;
	}
	Client* current = head;
	while (current->getNext() != nullptr && current->getNext()->getAccountID() < newClient->getAccountID())
	{
		current = current->getNext();
		if (current->getAccountID() == newClient->getAccountID())
		{
			// Duplicate ID found, do not add
			delete newClient; // Clean up memory
			return;
		}
	}
	newClient->setNext(current->getNext());
	current->setNext(newClient);
}

// Delete client
void ClientList::deleteClient(int accountID)
{
	// Empty list
	if (head == nullptr) 
	{
		return;
	}

	// Delete head
	if (head->getAccountID() == accountID)
	{
		Client* toDelete = head;
		head = head->getNext();
		delete toDelete;
		return;
	}

	// Delete non-head
	Client* current = head;
	while (current->getNext() != nullptr && current->getNext()->getAccountID() != accountID)
	{
		current = current->getNext();
	}
	if (current->getNext() != nullptr)
	{
		Client* toDelete = current->getNext();
		current->setNext(toDelete->getNext());
		delete toDelete;
	}
}

// Find client
std::string ClientList::findClient(int accountID)
{
	Client* current = head;
	while (current != nullptr)
	{
		if (current->getAccountID() == accountID)
		{
			return current->toString();
		}
		current = current->getNext();
	}
	return "Client not found.";
}

// Update client balance
void ClientList::updateClientBalance(int accountID, float newBalance)
{
	Client* current = head;
	while (current != nullptr)
	{
		if (current->getAccountID() == accountID)
		{
			current->setBalance(newBalance);
			return;
		}
		current = current->getNext();
	}
}

// Print all clients ordered by ID number. Does not modify the original list since it is already sorted by ID.
std::string ClientList::getAllClientsbyID()
{
	// if list is empty
	if (head == nullptr)
	{
		return "No clients in the list.";
	}

	// compile string of all clients
	std::string result;
	Client* current = head;
	while (current != nullptr)
	{
		result += current->toString();
		current = current->getNext();
	}
	return result;
}

// Print all clients ordered by name.
std::string ClientList::getAllClientsbyName()
{
	// if list is empty
	if (head == nullptr)
	{
		return "No clients in the list.";
	}

	// create a copy of the list to sort
	Client* sortedHead = nullptr;
	Client* current = head;

	// Insertion sort by name
	while (current != nullptr)
	{
		Client* newClient = new Client(current->getAccountID(), current->getName(), current->getBalance());
		// Insert into sorted list
		if (sortedHead == nullptr || newClient->getName() < sortedHead->getName())
		{
			newClient->setNext(sortedHead);
			sortedHead = newClient;
		}
		else
		{
			Client* sortedCurrent = sortedHead;
			while (sortedCurrent->getNext() != nullptr && sortedCurrent->getNext()->getName() < newClient->getName())
			{
				sortedCurrent = sortedCurrent->getNext();
			}
			newClient->setNext(sortedCurrent->getNext());
			sortedCurrent->setNext(newClient);
		}
		current = current->getNext();
	}

	// compile string of all clients from sorted list
	std::string result;
	current = sortedHead;
	while (current != nullptr)
	{
		result += current->toString();
		Client* toDelete = current;
		current = current->getNext();
		delete toDelete; // clean up
	}
	return result;
}

// Print all clients ordered by balance.
std::string ClientList::getAllClientsbyBalance()
{
	// if list is empty
	if (head == nullptr)
	{
		return "No clients in the list.";
	}

	// create a copy of the list to sort
	Client* sortedHead = nullptr;
	Client* current = head;

	// Insertion sort by balance

	while (current != nullptr)
	{
		Client* newClient = new Client(current->getAccountID(), current->getName(), current->getBalance());
		// Insert into sorted list
		if (sortedHead == nullptr || newClient->getBalance() < sortedHead->getBalance())
		{
			newClient->setNext(sortedHead);
			sortedHead = newClient;
		}
		else
		{
			Client* sortedCurrent = sortedHead;
			while (sortedCurrent->getNext() != nullptr && sortedCurrent->getNext()->getBalance() < newClient->getBalance())
			{
				sortedCurrent = sortedCurrent->getNext();
			}
			newClient->setNext(sortedCurrent->getNext());
			sortedCurrent->setNext(newClient);
		}
		current = current->getNext();
	}
	// compile string of all clients from sorted list
	std::string result;
	current = sortedHead;
	while (current != nullptr)
	{
		result += current->toString();
		Client* toDelete = current;
		current = current->getNext();
		delete toDelete; // clean up
	}
	return result;
}

// Check if list is empty
bool ClientList::isEmpty()
{
	return head == nullptr;
}

#endif // !CLIENTLIST_CPP