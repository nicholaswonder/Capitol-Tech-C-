#include "HashTablesApp.h"
#include <iostream>
#include <string>

int HashTableApp::hash(Contact con)
{
    // Probably a bad hash function but this is what I could think of quickly
    std::string name = con.getName(); // get name
    int id = 0;

    for (int i = 0; i < name.length(); i++)
    {
        id += static_cast<int>(name[i]); // add the ASCII values of all the letters in the name
    }
    id = id * name.length(); // multiply the id by the length of the name
    name.length() % 2 == 0 ? id = id * -1 : id = id; // If name is of even length, make the ID negative

    return id;
}

void HashTableApp::insertRecord(Contact con){
    int id = hash(con);
    records[id] = con;
    std::cout << "\nRecord Added: " << id << " -> " << con.getName() << std::endl;
}

void HashTableApp::findRecord(int id){
    std::unordered_map<int, Contact>::iterator it = records.find(id);

    if (it != records.end()){
        std::cout<<"Contact Found: "<<std::endl;
        std::cout<<it->second.toString()<<std::endl;
    }
    else {
        std::cout<<"Record not found!"<<std::endl;
    }
}

//Delete a record
void HashTableApp::deleteRecord(int id){
    std::unordered_map<int, Contact>::iterator it = records.find(id);

    if (records.erase(id)) {
        std::cout<<"Contact Deleted: "<<std::endl;
        std::cout<<it->second.toString()<<std::endl;
    } else{
        std::cout<<"Record not found!"<<std::endl;
    }
}

void HashTableApp::displayRecords(){
    if (records.empty())
    {
        std::cout<<"No records available!"<<std::endl;
    } else {
        for (auto& [id, contact] : records) {
            std::cout << "ID: " << id << "\n"<< contact.toString();
        }
    }
}