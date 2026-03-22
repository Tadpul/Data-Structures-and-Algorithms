#include "BinaryRecursiveTrees.h"
#include <iostream>
#include <queue>

// node constructor
Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

// binary tree constructors
BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(int val) : root(new Node(val)) {}

// binary tree member functions
bool BinaryTree::contains(Node* node, int val)
{
    if (node == nullptr) return false;

    if (node->value == val) return true;
    else if (node->value > val) return contains(node->left, val);
    else return contains(node->right, val);
}

bool BinaryTree::contains(int val) { return contains(root, val); }

Node* BinaryTree::insert(Node* currentNode, int val)
{
    if (currentNode == nullptr) return new Node(val);

    if (currentNode->value > val) currentNode->left = insert(currentNode->left, val);
    else if (currentNode->value < val) currentNode->right = insert(currentNode->right, val);
    return currentNode;
}

void BinaryTree::insert(int val) 
{
    if (root == nullptr) root = new Node(val);
    else insert(root, val);
}

int BinaryTree::minValue(Node* currentNode)
{
    if (currentNode->left == nullptr) return currentNode->value;

    return minValue(currentNode->left);
}

Node* BinaryTree::deleteNode(Node* currentNode, int val)
{
    // if the node to be deleted doesnt exist in the tree we return nullptr
    if (currentNode == nullptr) return nullptr;

    // this block traverses through the tree
    if (currentNode->value > val)
    {
        currentNode->left = deleteNode(currentNode->left, val);
    }
    else if (currentNode->value < val)
    {
        currentNode->right = deleteNode(currentNode->right, val);
    }

    // if the node is found take these steps
    else
    {
        // account for if there are no other nodes this node points to
        if (currentNode->left == nullptr && currentNode->right == nullptr)
        {
            delete currentNode;
            return nullptr;
        }
        // account for if the node only points to one branch (left or right)
        else if (currentNode->left == nullptr)
        {
            Node* temp{ currentNode->right };
            delete currentNode;
            return temp;
        }
        else if (currentNode->right == nullptr)
        {
            Node* temp{ currentNode->left };
            delete currentNode;
            return temp;
        }
        // account for if the node points to two branches (replace the current node with the smallest value to the right and then deletes that node from tree)
        else
        {
            int minInSubTree{ minValue(currentNode->right) };
            currentNode->value = minInSubTree;
            deleteNode(currentNode->right, minInSubTree);
        }
    }
    return currentNode;
}

void BinaryTree::BFS()
{
    std::queue<Node*> bfsQueue;
    bfsQueue.push(root);

    while (bfsQueue.size() != 0)
    {
        Node* currentNode{ bfsQueue.front() };
        bfsQueue.pop();
        std::cout << currentNode->value << ' ';

        if (currentNode->left)
        {
            bfsQueue.push(currentNode->left);
        }
        if (currentNode->right)
        {
            bfsQueue.push(currentNode->right);
        }
    }
}

void BinaryTree::DFS(Node* currentNode)
{
    std::cout << currentNode->value << ' ';
    if (currentNode->left) { DFS(currentNode->left); }
    if (currentNode->right) { DFS(currentNode->right); }
}

void BinaryTree::DFS() { DFS(root); }

void BinaryTree::deleteNode(int val) 
{
    // makes sure if root is deleted  it equals nullpointer (itself)
    root = deleteNode(root, val);
}