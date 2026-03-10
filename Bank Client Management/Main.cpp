#include "Client.h"
#include "ClientList.h"
#include <iostream>
#include <string>

using namespace std;

Client newClient()
{
	int accID;
	string name;
	float balance;
	// account ID input validation
	do
	{
		cin.clear(); // Clear error flag
		cout << "Enter account ID (positive integer): ";
		cin >> accID;
		if (cin.fail() || accID < 0)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid account ID. Please try again." << endl;
		}
	} while (cin.fail() || accID < 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer before reading string

	// client name input validation
	do
	{
		cin.clear(); // Clear error flag
		cout << "Enter client name: ";
		cin >> name;
		if (cin.fail())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid name. Please try again." << endl;
		}
	} while (cin.fail());

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer before reading float

	// balance input validation
	do
	{
		cin.clear(); // Clear error flag
		cout << "Enter initial balance: ";
		cin >> balance;
		if (cin.fail())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid balance. Please try again." << endl;
		}
	} while (cin.fail());

	Client client(accID, name, balance);
	return client;
}

int mainMenu()
{
	int option;
	cout << "Welcome to the Client Management System!" << endl;
	cout << "1. Add Client" << endl;
	cout << "2. Delete Client" << endl;
	cout << "3. Find Client" << endl;
	cout << "4. Update Client Balance" << endl;
	cout << "5. Display All Clients by ID" << endl;
	cout << "6. Display All Clients by Name" << endl;
	cout << "7. Display All Clients by Balance" << endl;
	cout << "8. Exit" << endl;
	cout << "Please select an option (1-8): ";
	do
	{
		cin.clear(); // Clear error flag
		cin >> option;
		if (cin.fail() || option < 1 || option > 8)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid account ID. Please try again." << endl;
		}
	} while (cin.fail() || option < 1 || option > 8);

	return option;
}

int main()
{
	ClientList clientList;
	int option;
	int accID;
	float newBalance;
	do
	{
		option = mainMenu();
		switch (option)
		{
		case 1:
		{
			Client client = newClient();
			Client* clientPtr = new Client(client.getAccountID(), client.getName(), client.getBalance());
			clientList.addClient(clientPtr);
			cout << "Client added successfully." << endl;
			break;
		}
		case 2:
		{
			if (!clientList.isEmpty())
			{
				cout << "Enter account ID to delete: ";
				cin >> accID;
				clientList.deleteClient(accID);
				cout << "Client deleted successfully." << endl;
			}
			else
			{
				cout << "Client list is empty. Cannot delete client." << endl;
			}
			break;
		}
		case 3:
		{
			if (!clientList.isEmpty())
			{
				cout << "Enter account ID to find: ";
				cin >> accID;
				cout << clientList.findClient(accID) << endl;
			}
			else
			{
				cout << "Client list is empty. Cannot find client." << endl;
			}
			break;
		}
		case 4:
		{
			if (!clientList.isEmpty())
			{
				cout << clientList.getAllClientsbyID() << endl;
				cout << "Enter account ID to update: ";
				cin >> accID;
				cout << "Enter new balance: ";
				cin >> newBalance;
				clientList.updateClientBalance(accID, newBalance);
				cout << "Client balance updated successfully." << endl;
			}
			else
			{
				cout << "Client list is empty. Cannot update balance." << endl;
			}
			break;
		}
		case 5:
			cout << clientList.getAllClientsbyID() << endl;
			break;
		case 6:
			cout << clientList.getAllClientsbyName() << endl;
			break;
		case 7:
			cout << clientList.getAllClientsbyBalance() << endl;
			break;
		case 8:
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	} while (option != 8);
	return 0;
}