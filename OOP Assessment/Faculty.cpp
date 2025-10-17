#include "Faculty.h"
#include <typeinfo>

// Constructors
Faculty::Faculty() : Person()
{
	rank = "";
	yearsOfService = 0;
	officeNum = 0;
}

Faculty::Faculty(int newID, string newFirst, string newLast, int newAge, string newRank, int newYears, int newOffice) : Person(newID, newFirst, newLast, newAge)
{
	rank = "";
	yearsOfService = 0;
	officeNum = 0;
	setRank(newRank);
	setYearsOfService(newYears);
	setOfficeNum(newOffice);
}

// Getters
string Faculty::getRank()
{
	return rank;
}

int Faculty::getYearsOfService()
{
	return yearsOfService;
}

int Faculty::getOfficeNum()
{
	return officeNum;
}

// Setters

void Faculty::setRank(string newRank)
{
	if (!newRank.empty())
	{
		rank = newRank;
	}
}

void Faculty::setYearsOfService(int newYears)
{
	if (newYears >= 0)
	{
		yearsOfService = newYears;
	}
}

void Faculty::setOfficeNum(int newOffice)
{
	if (newOffice > 0)
	{
		officeNum = newOffice;
	}
}

// toString
string Faculty::toString()
{
	return Person::toString() +
		"Rank: " + rank + "\n" +
		"Years of Service: " + to_string(yearsOfService) + "\n" +
		"Office Number: " + to_string(officeNum) + "\n";
}

// Equals
bool operator==(const Faculty& f1, const Faculty& f2)
{
	// Test if f1 and f2 are of class Faculty
	if (typeid(f1) == typeid(f2))
	{
		// Casting to Person to compare base class attributes
		return (static_cast<Person>(f1) == static_cast<Person>(f2)) && 
			f1.rank == f2.rank && 
			f1.yearsOfService == f2.yearsOfService &&
			f1.officeNum == f2.officeNum;
	}
	else
	{
		return false;
	}
}