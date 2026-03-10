#pragma once
#ifndef CLIENTLIST_H
#define CLIENTLIST_H
#include "Client.h"
#include <string>

class ClientList
{
private:
	Client* head;

public:
	// ClientList constructor and destructor
	ClientList();
	~ClientList();

	// add client - will sort clients by ID as they are added with insertion sort.
	void addClient(Client* newClient);

	// delete client
	void deleteClient(int accountID);

	// find client - returns client toString or "Client not found."
	std::string findClient(int accountID);

	// update client balance
	void updateClientBalance(int accountID, float newBalance);

	// return string of all clients - sorted by accountID
	std::string getAllClientsbyID();

	// return string of all clients - sorted by name
	std::string getAllClientsbyName();

	// return string of all clients - sorted by balance
	std::string getAllClientsbyBalance();

	// check if list is empty
	bool isEmpty();
};

#endif // !CLIENTLIST_H