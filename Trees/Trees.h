#pragma once

struct Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val);
};

class Tree
{
public:
    Node* root;

public:
    Tree();
    Tree(int val);
    bool insert(int val);
    bool contains(int val);
}; 
