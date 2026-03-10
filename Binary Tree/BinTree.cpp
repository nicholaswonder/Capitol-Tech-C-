#include "Node.h"
#include "BinTree.h"
#include <string>
#include <iostream>

using namespace std;

BinTree::BinTree()
{
    root = nullptr;
}

BinTree::~BinTree()
{
    // Simply uses the deleteChildren helper method in Node class, just begins it on the root.
    root->deleteChildren();
    delete root;
}

void BinTree::insertNode(Node* insertionNode, Node* newNode)
{
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    if(insertionNode->getData() >= newNode->getData())
    {
        if (insertionNode->getLesserChild() == nullptr)
        {
            insertionNode->setLesserChild(newNode);
            return;
        }
        else
        {
            insertNode(insertionNode->getLesserChild(), newNode);
        }
    }
    else
    {
        if (insertionNode->getGreaterChild() == nullptr)
        {
            insertionNode->setGreaterChild(newNode);
            return;
        }
        else
        {
            insertNode(insertionNode->getGreaterChild(), newNode);
        }
    }

}

Node* BinTree::search(Node* searchNode, int value)
{
    if(searchNode->getData() == value)
    {
        return searchNode;
    }
    else if(searchNode->getData() >= value && searchNode->getLesserChild() != nullptr)
    {
        return search(searchNode->getLesserChild(), value);
    }
    else if(searchNode->getData() < value && searchNode->getGreaterChild() != nullptr)
    {
        return search(searchNode->getGreaterChild(), value);
    }
    else
    {
        // This should only trigger if both child nodes are null
        // Meaning the search got to the end of the list and didnt find the searched value.
        return nullptr;
    }
}

Node* BinTree::getRoot()
{
    return root;
}

std::string BinTree::toString()
{
    // just calls the nodes tostring method on the root to get the whole tree
    return "Printing entire tree sorted:\n" + root->toString();
}