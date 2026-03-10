#include "Node.h"
#include "BinTree.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    BinTree tree;
    Node* searchReturn;
    int option, nodeValue = -1;
    do
    {
        cout << "Binary Tree Test" << endl;
        cout << "Select a function" << endl;
        cout << "1. Add new value to tree" << endl;
        cout << "2. Search for value in tree" << endl;
        cout << "3. Print contents of tree" << endl;
        cout << "4. Exit program" << endl;
        cout << "Desired function: ";
        cin >> option;

        switch(option)
        {
            case 1:
            cout << "Enter a value to insert into the tree: ";
            cin >> nodeValue;
            tree.insertNode(tree.getRoot(), new Node(nodeValue));
            cout << "Added value of " << nodeValue << endl;
            break;

            case 2:
            cout << "Enter a value to search for in the tree: ";
            cin >> nodeValue;
            searchReturn = tree.search(tree.getRoot(), nodeValue);
            cout << ((searchReturn == nullptr) ? "Value was not found" : to_string(nodeValue) + " was found!") << endl;
            break;

            case 3:
            cout << tree.toString() << endl;
            break;

            case 4:
            cout << "Exiting program..." << endl;
            break;

            default:
            cout << "Invalid selection" << endl;
        };

        cout << endl;

    } while (option != 4);

    // exit program
    return 0;
}