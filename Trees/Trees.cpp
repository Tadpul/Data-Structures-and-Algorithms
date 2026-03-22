#include "Trees.h"
#include <iostream>

// node constructor
Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

// tree constructors
Tree::Tree() : root(nullptr) {}

Tree::Tree(int val) : root(new Node(val)) {}

// tree member functions
bool Tree::insert(int val)
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

bool Tree::contains(int val)
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