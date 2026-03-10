#pragma once
#ifndef CLIENT_CPP
#define CLIENT_CPP
#include "Client.h"
#include <string>

Client::Client()
{
	accountID = 0;
	name = "NULL";
	balance = 0;
	next = nullptr;
}

Client::Client(int id, std::string clientName, float initialBalance)
{
	setAccountID(id);
	setName(clientName);
	setBalance(initialBalance);
	next = nullptr;
}

// getters
int Client::getAccountID()
{
	return accountID;
}

std::string Client::getName()
{
	return name;
}

float Client::getBalance()
{
	return balance;
}

Client* Client::getNext()
{
	return next;
}

// setters

void Client::setAccountID(int id)
{
	accountID = id;
}

void Client::setName(std::string clientName)
{
	name = clientName;
}

void Client::setBalance(float newBalance)
{
	balance = newBalance;
}

void Client::setNext(Client* nextClient)
{
	next = nextClient;
}

// toString method
std::string Client::toString()
{
	return "Account ID: " + std::to_string(accountID) + ", Name: " + name + ", Balance: $" + std::to_string(balance) + "\n";
}

#endif // CLIENT_CPP