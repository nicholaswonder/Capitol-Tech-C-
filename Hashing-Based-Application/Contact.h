#pragma once
#include <string>

class Contact{
    private:
        unsigned long long phoneNum;
        std::string email;
        std::string name;

    public:
        Contact();
        Contact(std::string newName, unsigned long long newPhone, std::string email);

        std::string getName();
        unsigned long long getPhoneNum();
        std::string getEmail();

        void setName(std::string newName);
        void setPhoneNum(unsigned long long newPhone);
        void setEmail(std::string email);

        std::string toString();
};