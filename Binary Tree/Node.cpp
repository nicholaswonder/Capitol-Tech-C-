#include "Node.h"

Node::Node()
{
    data = 0;
    greaterChild = nullptr;
    lesserChild = nullptr;
}

Node::Node(int newData)
{
    setData(newData);
    greaterChild = nullptr;
    lesserChild = nullptr;
}

int Node::getData()
{
    return data;
}

void Node::setData(int newData)
{
    data = newData;
}

Node* Node::getGreaterChild()
{
    return greaterChild;
}

Node* Node::getLesserChild()
{
    return lesserChild;
}

void Node::setGreaterChild(Node* newNode)
{
    if(newNode->getData() > this->data) // Ensure the new data is going in correctly
    {
        greaterChild = newNode;
    }
}

void Node::setLesserChild(Node* newNode)
{
    if(newNode->getData() <= this->data) // Ensure the new data is going in correctly
    {
        lesserChild = newNode;
    }
}

// BEGIN NEW TOSTRING FUNCTION //

// This function prints the content of the node plus the contents of the children recursively
std::string Node::toString()
{
    std::string returnString = "";

    // Get all values LESS than current node

    if (getLesserChild() != nullptr) 
    {
        returnString += getLesserChild()->toString();
    }

    // Add current node to string

    returnString += std::to_string(getData()) + " ";

    // Get all values GREATER than current node

    if (getGreaterChild() != nullptr)
    {
        returnString += getGreaterChild()->toString();
    }

    return returnString;
}

// END NEW TOSTRING FUNCTION

void Node::deleteChildren()
{
    if (lesserChild != nullptr)
    {
        lesserChild->deleteChildren();
        delete lesserChild;
    }

    if (greaterChild != nullptr)
    {
        greaterChild->deleteChildren();
        delete greaterChild;
    }
}