#pragma once

struct Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val);
};

class BinaryTree
{
public:
    Node* root;

public:
    BinaryTree();
    BinaryTree(int val);
    bool contains(Node* node, int val);
    bool contains(int val);
    Node* insert(Node* currentNode, int val);
    void insert(int val);
    int minValue(Node* currentNode);
    Node* deleteNode(Node* currentNode, int val);
    void BFS();
    void DFS(Node* currentNode);
    void DFS();
    void deleteNode(int val);
};