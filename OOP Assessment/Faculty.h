#pragma once
#include "Person.h"
#include <string>

class Faculty : public Person
{
private:
	string rank;
	int yearsOfService;
	int officeNum;

public:
	// Constructors
	Faculty();
	Faculty(int, string, string, int, string, int, int);

	// Getters
	string getRank();
	int getYearsOfService();
	int getOfficeNum();

	// Setters
	void setRank(string);
	void setYearsOfService(int);
	void setOfficeNum(int);

	// toString override
	string toString() override;

	// Equals override
	friend bool operator==(const Faculty& f1, const Faculty& f2);
};

