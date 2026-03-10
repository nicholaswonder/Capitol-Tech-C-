#include "QueueManager.h"
#include <iostream>

using namespace std;

// Menu for queue program
void queueMenu() {
    QueueManager qm;
    int choice;
    string record;

    do {
        cout << "\n--- Queue Management System ---\n";
        cout << "1. Add Record\n2. Find Record\n3. Delete Oldest Record\n4. View All Records\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter record: ";
            getline(cin, record);
            qm.addRecord(record);
            break;
        case 2:
            cout << "Enter record to find: ";
            getline(cin, record);
            qm.findRecord(record);
            break;
        case 3:
            qm.deleteRecord();
            break;
        case 4:
            qm.viewRecords();
            break;
        case 5:
            cout << "Exiting queue program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

// Main function for queue program
int main() {
    queueMenu();
    return 0;
}