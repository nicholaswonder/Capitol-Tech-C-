#include "Contact.h"
#include <string>

Contact::Contact()
{
    name = "";
    email = "";
    phoneNum = 0;
}

Contact::Contact(std::string newName, unsigned long long newPhone, std::string newEmail){
    setName(newName);
    setPhoneNum(newPhone);
    setEmail(newEmail);
}

std::string Contact::getName()
{
    return name;
}

unsigned long long Contact::getPhoneNum()
{
    return phoneNum;
}

std::string Contact::getEmail()
{
    return email;
}

void Contact::setName(std::string newName)
{
    name = newName;
}

void Contact::setPhoneNum(unsigned long long newPhone)
{
    if (newPhone <= 9999999999)
    {
        phoneNum = newPhone;
    }
}

void Contact::setEmail(std::string newEmail)
{
    email = newEmail;
}

std::string Contact::toString()
{
    return getName() + ":\n"
        + std::to_string(getPhoneNum()) + "\n"
        + getEmail() + "\n\n";
}