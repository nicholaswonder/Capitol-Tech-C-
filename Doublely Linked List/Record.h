#pragma once
#include <string>
class Record
{
private:
	Record* next;
	Record* prev;
	std::string name;
	int accountNum;
	float balance;

public:
	Record();
	Record(int accNum, std::string newName, float newBalance);

	void setNext(Record* nextRecord);
	void setPrev(Record* prevRecord);
	void setName(std::string newName);
	void setAccountNum(int accNum);
	void setBalance(float newBalance);

	Record* getNext();
	Record* getPrev();
	std::string getName();
	int getAccountNum();
	float getBalance();

	std::string toString();
};

