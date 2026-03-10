#pragma once
#include <string>

class Node
{
    private:
    int data;
    Node* lesserChild; // Holds a child with a value less than itself
    Node* greaterChild; // Holds a child with a value greater than itself

    public:
    Node();
    Node(int newData);

    void setData(int newData);
    int getData();

    Node* getLesserChild();
    Node* getGreaterChild();

    void setLesserChild(Node* newNode);
    void setGreaterChild(Node* newNode);

    // Self-serving, but a good helper for the binary tree too
    std::string toString();

    // Helper method for binary tree destructor
    void deleteChildren();
};