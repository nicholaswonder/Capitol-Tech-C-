#include "Contact.h"
#include <unordered_map>
#include <string>

class HashTableApp {
    private:
        std::unordered_map<int, Contact> records; //Hash table (Key: ID, Value: Name)
        
    public:
        //insert record
        void insertRecord(Contact);
        void findRecord(int);
        void deleteRecord(int);
        void displayRecords();
        int hash(Contact);
};