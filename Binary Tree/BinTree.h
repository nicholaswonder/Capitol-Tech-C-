#include "Node.h"
#include <string>

class BinTree
{
    private:
    Node* root;

    public:
    BinTree();
    ~BinTree();

    void insertNode(Node* insertionNode, Node* newNode);
    Node* search(Node* searchNode, int value);
    Node* getRoot();

    std::string toString();
};