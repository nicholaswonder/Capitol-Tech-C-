#pragma once
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class QueueManager {
private:
    queue<string> records;

public:
    // Add a record to the queue
    void addRecord(const string& record);

    // Find a record (checks if it exists in the queue)
    bool findRecord(const string& record);

    // Delete the oldest record (FIFO)
    void deleteRecord();

    // View all records (front to back)
    void viewRecords();
};