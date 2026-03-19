#include <iostream>

struct Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(int val) : root(new Node(val)) {}

    bool contains(Node* node, int val)
    {
        if (node == nullptr) return false;

        if (node->value == val) return true;
        else if (node->value > val) return contains(node->left, val);
        else return contains(node->right, val);
    }

    bool contains(int val) { return contains(root, val); }

    Node* insert(Node* currentNode, int val)
    {
        if (currentNode == nullptr) return new Node(val);

        if (currentNode->value > val) currentNode->left = insert(currentNode->left, val);
        else if (currentNode->value < val) currentNode->right = insert(currentNode->right, val);
        return currentNode;
    }

    void insert(int val) 
    {
        if (root == nullptr) root = new Node(val);
        else insert(root, val);
    }

    Node* deleteNode(Node* currentNode, int val)
    {
        if (currentNode == nullptr) return nullptr;

        if (currentNode->value > val)
        {
            currentNode = deleteNode(currentNode->left, val);
        }
        else if (currentNode->value < val)
        {
            currentNode = deleteNode(currentNode->right, val);
        }
        else
        {
            return nullptr;
        }
        return currentNode;
    }

    Node* deleteNode(int val) 
    {
        Node* currentNode = deleteNode(root, val);
        return currentNode;
    }
};

int main()
{
    BinaryTree myBT;
    myBT.insert(2);
    myBT.insert(3);
    myBT.insert(89);
    myBT.insert(4);
    myBT.insert(6);
    myBT.insert(1);
    std::cout << myBT.contains(8);
    myBT.deleteNode(6);
}