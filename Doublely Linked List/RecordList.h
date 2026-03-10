#pragma once
#include "Record.h"
#include <string>

class RecordList
{
private:
	Record* head;

public:
	RecordList();
	~RecordList();

	void addRecord(Record newRecord);
	void deleteRecord(int accountNum);
	std::string findRecord(int accountNum);
	void EditRecord(int accountNum, float newBalance);
	std::string toString();
};

