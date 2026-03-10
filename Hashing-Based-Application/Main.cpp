#include "Contact.h"
#include "HashTablesApp.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Contact newContact(){
    string name;
    unsigned long long phoneNum;
    string email;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter new contacts name" << endl;
    getline(cin, name);
    cout << "Enter new contacts phone number" << endl;
    cin >> phoneNum;
    cout << "Enter new contacts email address" << endl;
    cin >> email;

    return Contact(name,phoneNum,email);
}

int main(){   
    Contact test;
    HashTableApp table;
    int choice, id;
    do {
        cout<<"Welcome to the Hash Table App\n"<<"-----------------------"<<endl;
        cout << "\n1. Add Record\n2. Find Record\n3. Delete Record\n4. View All Records\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                test = newContact();
                table.insertRecord(test);
                cout << test.toString() << endl;
                break;
            case 2:
                cout << "Enter ID to search: ";
                cin >> id;
                table.findRecord(id);
                break;
            case 3:
                cout << "Enter ID to delete: ";
                cin >> id;
                table.deleteRecord(id);
                break;
            case 4:
                table.displayRecords();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}