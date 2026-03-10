#include "QueueManager.h"
#include <iostream>
#include <queue>

using namespace std;

// Add a record to the queue
void QueueManager::addRecord(const string& record) {
    records.push(record);
    cout << "Record added successfully.\n";
}

// Find a record (checks if it exists in the queue)
bool QueueManager::findRecord(const string& record) {
    queue<string> tempQueue = records;
    while (!tempQueue.empty()) {
        if (tempQueue.front() == record) {
            cout << "Record found: " << record << endl;
            return true;
        }
        tempQueue.pop();
    }
    cout << "Record not found.\n";
    return false;
}

// Delete the oldest record (FIFO)
void QueueManager::deleteRecord() {
    if (!records.empty()) {
        cout << "Deleted record: " << records.front() << endl;
        records.pop();
    }
    else {
        cout << "Queue is empty. Nothing to delete.\n";
    }
}

// View all records (front to back)
void QueueManager::viewRecords() {
    if (records.empty()) {
        cout << "No records to display.\n";
        return;
    }
    queue<string> tempQueue = records;
    cout << "\nQueue Records (Front to Back):\n";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << endl;
        tempQueue.pop();
    }
}