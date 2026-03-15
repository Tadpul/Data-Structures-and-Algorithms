#include <iostream>

struct Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree
{
public:
    Node* root;

public:
    Tree() : root(nullptr) {}

    Tree(int val) : root(new Node(val)) {}

    bool insert(int val)
    {
        Node* newNode{ new Node(val) };
        Node* temp{ root };
        while (temp)
        {
            if (val == temp->value) { return false; }
            if (val < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else if (val > temp->value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
        // if root (temp) points too a null pointer, simply create a new node and add it to the tree
        root = newNode;
        return true;
    }

    bool contains(int val)
    {
        Node* temp = root;
        while (temp)
        {
            if (val < temp->value)
            {
                temp = temp->left;
            }
            else if (val > temp->value)
            {
                temp = temp->right;
            }
            else { return true; }
        }
        return false;
    }
};

int main()
{
    
}