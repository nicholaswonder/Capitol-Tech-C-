#include "RecordList.h"
#include <string>

RecordList::RecordList()
{
	head = nullptr;
}

RecordList::~RecordList()
{
	Record* current = head;
	head = nullptr;
	while (current != nullptr)
	{
		Record* toDelete = current;
		current = current->getNext();
		delete toDelete;
	}
}

// Sorts entries in descending order based on balance on insertion
void RecordList::addRecord(Record newRecord)
{
	Record* newRecPtr = new Record(newRecord.getAccountNum(), newRecord.getName(), newRecord.getBalance());
	if (head == nullptr)
	{
		head = newRecPtr;
	}
	else if (newRecPtr->getBalance() > head ->getBalance())
	{
		newRecPtr->setNext(head);
		head->setPrev(newRecPtr);
		head = newRecPtr;
	}
	else
	{
		Record* current = head;
		while (current->getNext() != nullptr && current->getNext()->getBalance() >= newRecPtr->getBalance())
		{
			current = current->getNext();
			if (newRecPtr->getBalance() > current->getBalance())
			{
				// Set new nodes next/prev
				newRecPtr->setNext(current);
				newRecPtr->setPrev(current->getPrev());

				// Set current nodes Previous
				current->setPrev(newRecPtr);

				// Set previous nodes Next
				current->getPrev()->setNext(newRecPtr);
				break;
			} 
			else if(current->getNext() == nullptr)
			{
				current->setNext(newRecPtr);
				newRecPtr->setPrev(current);
				break;
			}
		}
	}
}

void RecordList::deleteRecord(int accountNum)
{
	Record* current = head;
	while (current != nullptr)
	{
		if (current->getAccountNum() == accountNum)
		{
			if (current->getPrev() != nullptr)
			{
				current->getPrev()->setNext(current->getNext());
			}
			else
			{
				head = current->getNext();
			}
			if (current->getNext() != nullptr)
			{
				current->getNext()->setPrev(current->getPrev());
			}
			delete current;
			return;
		}
		current = current->getNext();
	}
}

std::string RecordList::findRecord(int accountNum)
{
	Record* current = head;
	while (current != nullptr)
	{
		if (current->getAccountNum() == accountNum)
		{
			return current->toString();
		}
		current = current->getNext();
	}
	return "Record not found.";
}

void RecordList::EditRecord(int accountNum, float newBalance)
{
	Record* current = head;
	while (current != nullptr)
	{
		if (current->getAccountNum() == accountNum)
		{
			current->setBalance(newBalance);
			return;
		}
		current = current->getNext();
	}
}

std::string RecordList::toString()
{
	std::string result;
	Record* current = head;
	while (current != nullptr)
	{
		result += current->toString() + "\n";
		current = current->getNext();
	}
	return result;
}