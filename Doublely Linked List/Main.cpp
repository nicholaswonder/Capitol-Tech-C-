#include "Record.h"
#include "RecordList.h"
#include <iostream>
#include <string>

using namespace std;

Record createRecord()
{
	int accNum;
	string name;
	float balance;
	cout << "Enter account number: ";
	cin >> accNum;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter balance: ";
	cin >> balance;
	return Record(accNum, name, balance);
}

int menu()
{
	cout << "1. Add Record" << endl;
	cout << "2. Delete Record" << endl;
	cout << "3. Find Record" << endl;
	cout << "4. Edit Record" << endl;
	cout << "5. Display All Records" << endl;
	cout << "6. Exit" << endl;
	cout << "Choose an option: ";
	int choice;
	cin >> choice;
	return choice;
}

int main()
{
	RecordList recordList;
	int choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
		{
			Record newRecord = createRecord();
			recordList.addRecord(newRecord);
			break;
		}
		case 2:
		{
			int accNum;
			cout << "Enter account number to delete: ";
			cin >> accNum;
			recordList.deleteRecord(accNum);
			break;
		}
		case 3:
		{
			int accNum;
			cout << "Enter account number to find: ";
			cin >> accNum;
			cout << recordList.findRecord(accNum) << endl;
			break;
		}
		case 4:
		{
			int accNum;
			float newBalance;
			cout << "Enter account number to edit: ";
			cin >> accNum;
			cout << "Enter new balance: ";
			cin >> newBalance;
			recordList.EditRecord(accNum, newBalance);
			break;
		}
		case 5:
			cout << recordList.toString() << endl;
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 6);
	return 0;
}