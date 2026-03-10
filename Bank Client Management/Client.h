#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
private:
	unsigned int accountID;
	std::string name;
	float balance;
	Client* next;

public:
	Client();
	Client(int id, std::string clientName, float initialBalance);

	// getters
	int getAccountID();
	std::string getName();
	float getBalance();
	Client* getNext();

	// setters
	void setAccountID(int id);
	void setName(std::string clientName);
	void setBalance(float newBalance);
	void setNext(Client* nextClient);

	// toString method
	std::string toString();
};

#endif // CLIENT_H