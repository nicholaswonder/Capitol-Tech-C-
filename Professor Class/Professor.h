#include <string>

using namespace std;

class Professor
{
private:
	string firstName;
	string lastName;
	bool tenure;
	short officeNum;

public:
	// Constructors
	Professor();
	Professor(string, string, bool, short);

	// Getters
	string getFirstName();
	string getLastName();
	bool isTenured();
	short getOfficeNum();

	// Setters
	void setFirstName(string);
	void setLastName(string);
	void setTenure(bool);
	void setOfficeNum(short);

	// toString
	string toString();
};