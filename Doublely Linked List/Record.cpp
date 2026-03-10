#include "Record.h"

Record::Record()
{
	next = nullptr;
	prev = nullptr;
	name = "";
	accountNum = 0;
	balance = 0.0f;
}

Record::Record(int accNum, std::string newName, float newBalance)
{
	next = nullptr;
	prev = nullptr;
	setName(newName);
	setAccountNum(accNum);
	setBalance(newBalance);
}

void Record::setNext(Record* nextRecord)
{
	next = nextRecord;
}

void Record::setPrev(Record* prevRecord)
{
	prev = prevRecord;
}

void Record::setName(std::string newName)
{
	name = newName;
}

void Record::setAccountNum(int accNum)
{
	if (accNum >= 1)
	{
		accountNum = accNum;
	}
}

void Record::setBalance(float newBalance)
{
	balance = newBalance;
}

Record* Record::getNext()
{
	return next;
}

Record* Record::getPrev()
{
	return prev;
}

std::string Record::getName()
{
	return name;
}

int Record::getAccountNum()
{
	return accountNum;
}

float Record::getBalance()
{
	return balance;
}

std::string Record::toString()
{
	return "Account Number: " + std::to_string(accountNum) + ", Name: " + name + ", Balance: $" + std::to_string(balance);
}